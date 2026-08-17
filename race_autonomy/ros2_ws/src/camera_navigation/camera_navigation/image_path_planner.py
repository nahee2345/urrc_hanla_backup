"""Original-image-coordinate path planning; deliberately contains no BEV geometry."""

from dataclasses import dataclass
import time

import cv2
import numpy as np


VALID, DEGRADED, INVALID, INACTIVE = "VALID", "DEGRADED", "INVALID", "INACTIVE"
BOTH_BOUNDARIES = "BOTH_BOUNDARIES"
LEFT_BOUNDARY = "LEFT_BOUNDARY"
RIGHT_BOUNDARY = "RIGHT_BOUNDARY"
ROAD_CENTER = "ROAD_CENTER"
TEMPORAL_FALLBACK = "TEMPORAL_FALLBACK"


def camera_owns_path(section, intersection_sections=(4, 6, 8, 11)):
    """Ownership is section based; direction is intentionally not an input."""
    return int(section) not in {int(value) for value in intersection_sections}


@dataclass
class PlannerConfig:
    vehicle_center_x_px: float = 320.0
    roi_top: int = 120
    roi_bottom: int = 475
    sample_interval_px: int = 10
    sample_band_half_height_px: int = 2
    seed_half_width_px: int = 80
    seed_height_px: int = 24
    minimum_component_pixels: int = 20
    maximum_lateral_jump_px: float = 90.0
    road_containment_tolerance_px: int = 8
    exclusion_overlap_ratio: float = 0.35
    polynomial_degree: int = 2
    temporal_alpha: float = 0.35
    maximum_temporal_shift_px: float = 55.0
    max_temporal_fallback_frames: int = 5
    both_weight: float = 1.0
    single_weight: float = 0.72
    road_weight: float = 0.48
    temporal_weight: float = 0.25
    valid_min_points: int = 8
    valid_min_both_ratio: float = 0.55
    valid_min_confidence: float = 0.55
    # Single-boundary rows only get a LEFT/RIGHT_BOUNDARY estimate when a
    # learned lane width exists; previously that required the exact sample
    # row to have seen a BOTH_BOUNDARIES detection at some point, so rows
    # that rarely (or never) get both edges at once (common near the top of
    # the ROI, where lines converge) always fell back to the coarser
    # ROAD_CENTER estimate even with a confident single edge. This radius
    # lets that row borrow the width learned at the nearest row instead,
    # since lane width changes gradually with y (perspective), not
    # row-to-row. Does not affect BOTH_BOUNDARIES detection or both_ratio.
    width_profile_lookup_radius_px: float = 30.0
    # Lane-width sanity gate (sections 9/10): a per-row pair is only treated as a
    # trustworthy lane pair, and only allowed to update the learned width profile,
    # if it stays close to the recently observed width at that row. A pair that
    # suddenly opens up (intersection / lane opening) is kept as a lower-confidence
    # sample instead of being fed back into the width model or trusted at full weight.
    lane_width_relative_tolerance: float = 0.5
    lane_width_absolute_tolerance_px: float = 30.0


@dataclass
class PathResult:
    points: np.ndarray
    sources: list
    confidence: float
    state: str
    valid: bool
    latency_ms: float
    road_component: np.ndarray
    left: np.ndarray
    right: np.ndarray
    raw: np.ndarray
    diagnostics: dict = None
    confidence_components: dict = None


def _binary(mask):
    return (np.asarray(mask) > 0).astype(np.uint8)


def ego_connected_component(road, center_x, seed_half_width, seed_height,
                            minimum_pixels=20):
    mask = _binary(road)
    count, labels, stats, _ = cv2.connectedComponentsWithStats(mask, 8)
    if count <= 1:
        return np.zeros_like(mask)
    height, width = mask.shape
    x1, x2 = max(0, int(center_x-seed_half_width)), min(width, int(center_x+seed_half_width+1))
    y1 = max(0, height-int(seed_height))
    seed_labels = labels[y1:height, x1:x2]
    candidates = [(int(np.count_nonzero(seed_labels == label)), label)
                  for label in range(1, count)
                  if stats[label, cv2.CC_STAT_AREA] >= minimum_pixels]
    if not candidates or max(candidates)[0] == 0:
        return np.zeros_like(mask)
    label = max(candidates)[1]
    return (labels == label).astype(np.uint8)


def exclude_transverse_markings(lane_mask, words, stop, c_line, ratio=0.35):
    lane = _binary(lane_mask)
    exclusion = _binary(words) | _binary(stop) | _binary(c_line)
    count, labels, stats, _ = cv2.connectedComponentsWithStats(lane, 8)
    output = np.zeros_like(lane)
    for label in range(1, count):
        component = labels == label
        area = int(stats[label, cv2.CC_STAT_AREA])
        overlap = int(np.count_nonzero(component & exclusion.astype(bool)))
        if area and overlap/area < ratio:
            output[component] = 1
    return output


def exclude_one_semantic(lane_mask, exclusion_mask, ratio):
    lane = _binary(lane_mask); exclusion = _binary(exclusion_mask)
    count, labels, stats, _ = cv2.connectedComponentsWithStats(lane, 8)
    output = np.zeros_like(lane); removed = 0
    for label in range(1, count):
        component = labels == label; area = int(stats[label, cv2.CC_STAT_AREA])
        overlap = int(np.count_nonzero(component & exclusion.astype(bool)))
        if area and overlap/area >= ratio:
            removed += 1
        else:
            output[component] = 1
    return output, removed


def _runs(xs):
    if not len(xs):
        return []
    split = np.where(np.diff(xs) > 1)[0] + 1
    return [part for part in np.split(xs, split) if len(part)]


class ImagePathPlanner:
    def __init__(self, config=None):
        self.config = config or PlannerConfig()
        self.previous = None
        self.previous_confidence = 0.0
        self.fallback_age = 0
        self.width_profile = {}

    def reset(self):
        self.previous = None
        self.previous_confidence = 0.0
        self.fallback_age = 0

    def inactive(self, shape=(480, 640)):
        self.reset()
        empty = np.empty((0, 2), dtype=float)
        return PathResult(empty, [], 0.0, INACTIVE, False, 0.0,
                          np.zeros(shape, np.uint8), empty, empty, empty)

    def _samples(self, road, lane):
        cfg = self.config
        height, width = road.shape
        top, bottom = max(0, cfg.roi_top), min(height-1, cfg.roi_bottom)
        ys = list(range(bottom, top-1, -max(1, cfg.sample_interval_px)))
        left, right, road_edges = [], [], []
        counters = {"NO_ROAD": 0, "NO_BOUNDARY": 0, "LATERAL_JUMP": 0,
                    "ROAD_CONTAINMENT_FAILURE": 0}
        previous_left = previous_right = None
        for y in ys:
            y1, y2 = max(0, y-cfg.sample_band_half_height_px), min(height, y+cfg.sample_band_half_height_px+1)
            road_x = np.flatnonzero(np.any(road[y1:y2], axis=0))
            if not len(road_x):
                counters["NO_ROAD"] += 1
                continue
            road_left, road_right = float(road_x.min()), float(road_x.max())
            road_edges.append((y, road_left, road_right))
            lane_x = np.flatnonzero(np.any(lane[y1:y2], axis=0))
            candidates = [float(np.mean(run)) for run in _runs(lane_x)
                          if len(run) >= max(1, cfg.minimum_component_pixels//10)]
            lc = [x for x in candidates if x < cfg.vehicle_center_x_px]
            rc = [x for x in candidates if x > cfg.vehicle_center_x_px]
            lx = max(lc) if lc else None
            rx = min(rc) if rc else None
            if lx is None and rx is None: counters["NO_BOUNDARY"] += 1
            if lx is not None and previous_left is not None and abs(lx-previous_left) > cfg.maximum_lateral_jump_px:
                lx = None; counters["LATERAL_JUMP"] += 1
            if rx is not None and previous_right is not None and abs(rx-previous_right) > cfg.maximum_lateral_jump_px:
                rx = None; counters["LATERAL_JUMP"] += 1
            if lx is not None and road_left-cfg.road_containment_tolerance_px <= lx <= road_right+cfg.road_containment_tolerance_px:
                left.append((lx, float(y))); previous_left = lx
            elif lx is not None:
                counters["ROAD_CONTAINMENT_FAILURE"] += 1
            if rx is not None and road_left-cfg.road_containment_tolerance_px <= rx <= road_right+cfg.road_containment_tolerance_px:
                right.append((rx, float(y))); previous_right = rx
            elif rx is not None:
                counters["ROAD_CONTAINMENT_FAILURE"] += 1
        return (ys, np.asarray(left, float).reshape(-1, 2),
                np.asarray(right, float).reshape(-1, 2), road_edges, counters)

    @staticmethod
    def _at_y(points, y, tolerance):
        if not len(points): return None
        index = int(np.argmin(np.abs(points[:, 1]-y)))
        return float(points[index, 0]) if abs(points[index, 1]-y) <= tolerance else None

    def _width_near(self, y, radius):
        if not self.width_profile: return None
        nearest = min(self.width_profile, key=lambda row: abs(row-y))
        return self.width_profile[nearest] if abs(nearest-y) <= radius else None

    def _raw_path(self, ys, left, right, road_edges):
        cfg = self.config
        edge_by_y = {int(y): (a, b) for y, a, b in road_edges}
        points, sources, weights = [], [], []
        for y in ys:
            edges = edge_by_y.get(int(y))
            if edges is None: continue
            lx = self._at_y(left, y, cfg.sample_interval_px/2)
            rx = self._at_y(right, y, cfg.sample_interval_px/2)
            if lx is not None and rx is not None and rx > lx:
                width = rx-lx
                old = self.width_profile.get(int(y), width)
                tolerance = max(cfg.lane_width_absolute_tolerance_px, cfg.lane_width_relative_tolerance*old)
                width_is_sane = int(y) not in self.width_profile or abs(width-old) <= tolerance
                if width_is_sane:
                    self.width_profile[int(y)] = .8*old+.2*width
                    x, source, weight = (lx+rx)/2, BOTH_BOUNDARIES, cfg.both_weight
                else:
                    # Sudden widening/narrowing (intersection, lane opening): keep the
                    # midpoint as a sample but do not trust it fully and do not let it
                    # corrupt the learned width used for future single-boundary estimates.
                    x, source, weight = (lx+rx)/2, BOTH_BOUNDARIES, cfg.road_weight
            elif lx is not None and self._width_near(int(y), cfg.width_profile_lookup_radius_px) is not None:
                x, source, weight = lx+self._width_near(int(y), cfg.width_profile_lookup_radius_px)/2, LEFT_BOUNDARY, cfg.single_weight
            elif rx is not None and self._width_near(int(y), cfg.width_profile_lookup_radius_px) is not None:
                x, source, weight = rx-self._width_near(int(y), cfg.width_profile_lookup_radius_px)/2, RIGHT_BOUNDARY, cfg.single_weight
            else:
                x, source, weight = (edges[0]+edges[1])/2, ROAD_CENTER, cfg.road_weight
            if edges[0]-cfg.road_containment_tolerance_px <= x <= edges[1]+cfg.road_containment_tolerance_px:
                if points and abs(x-points[-1][0]) > cfg.maximum_lateral_jump_px:
                    continue
                points.append((x, float(y))); sources.append(source); weights.append(weight)
        return np.asarray(points, float).reshape(-1, 2), sources, np.asarray(weights, float)

    def _fit(self, raw, weights):
        if len(raw) < 3: return raw.copy()
        degree = min(self.config.polynomial_degree, len(raw)-1)
        normalized_y = raw[:, 1] / max(1.0, float(np.max(raw[:, 1])))
        coefficients = np.polyfit(normalized_y, raw[:, 0], degree, w=weights)
        return np.column_stack((np.polyval(coefficients, normalized_y), raw[:, 1]))

    def plan(self, road, white, yellow, words=None, stop=None, c_line=None):
        started = time.perf_counter()
        shape = np.asarray(road).shape
        zero = np.zeros(shape, np.uint8)
        words, stop, c_line = [zero if item is None else item for item in (words, stop, c_line)]
        component = ego_connected_component(road, self.config.vehicle_center_x_px,
                                            self.config.seed_half_width_px,
                                            self.config.seed_height_px,
                                            self.config.minimum_component_pixels)
        lane_before = _binary(white) | _binary(yellow)
        lane, words_removed = exclude_one_semantic(
            lane_before, words, self.config.exclusion_overlap_ratio)
        lane, stop_removed = exclude_one_semantic(
            lane, stop, self.config.exclusion_overlap_ratio)
        lane, c_line_removed = exclude_one_semantic(
            lane, c_line, self.config.exclusion_overlap_ratio)
        ys, left, right, edges, rejections = self._samples(component, lane)
        rejections.update({"WORDS_OVERLAP": words_removed, "STOP_OVERLAP": stop_removed,
                           "C_LINE_OVERLAP": c_line_removed,
                           "TOO_SMALL_COMPONENT": 0, "CONTINUITY_FAILURE": 0,
                           "INVALID_LANE_WIDTH": 0, "TEMPORAL_REJECT": 0})
        raw, sources, weights = self._raw_path(ys, left, right, edges)
        both_ratio = sources.count(BOTH_BOUNDARIES)/max(1, len(sources))
        road_score = min(1.0, len(edges)/max(1, max(8, len(ys)//3)))
        coverage_score = min(1.0, len(raw)/max(1, len(edges)))
        boundary_score = float(np.mean(weights)) if len(weights) else 0.0
        near_count = sum(y >= self.config.roi_bottom-100 for _, y in raw)
        near_score = min(1.0, near_count/max(1, min(8, len(raw))))
        continuity_score = max(0.0, 1.0-rejections["LATERAL_JUMP"]/max(1, len(raw)))
        components = {"road_score": road_score, "boundary_score": boundary_score,
                      "coverage_score": coverage_score, "near_field_score": near_score,
                      "continuity_score": continuity_score, "lane_width_score": both_ratio,
                      "temporal_score": 1.0, "freshness_score": 1.0}
        diagnostics = {"road_sample_rows": len(edges),
                       "lane_candidate_rows": len({int(y) for _, y in np.vstack((left, right))}) if len(left)+len(right) else 0,
                       "left_candidate_rows": len(left), "right_candidate_rows": len(right),
                       "lane_pixels_before_exclusion": int(np.count_nonzero(lane_before)),
                       "lane_pixels_after_exclusion": int(np.count_nonzero(lane)),
                       "raw_center_points": len(raw), "fitting_input_points": len(raw),
                       "rejections": rejections}
        if len(raw) >= 3:
            fitted = self._fit(raw, weights)
            confidence = float(np.clip(.18*road_score + .20*boundary_score +
                                       .18*coverage_score + .18*near_score +
                                       .12*continuity_score + .08*both_ratio + .06, 0.0, 1.0))
            if self.previous is not None and len(self.previous):
                # The y-grid sampled each frame is fixed by config (roi/interval),
                # but which rows survive to `fitted` varies frame to frame (edges
                # missing, lateral-jump rejects, etc.), so an exact length match
                # rarely holds -- previously that meant smoothing was skipped
                # entirely whenever the point count differed (observed ~9% of
                # frame pairs), letting the raw, unsmoothed fit through and
                # producing large lateral/heading jumps. Match by y instead, same
                # tolerance/lookup as _raw_path already uses for left/right.
                previous_x = [self._at_y(self.previous, y, self.config.sample_interval_px/2)
                              for y in fitted[:, 1]]
                matched = np.asarray([value is not None for value in previous_x])
                if matched.any():
                    previous_aligned = np.where(
                        matched, np.asarray([v if v is not None else 0.0 for v in previous_x]),
                        fitted[:, 0])
                    shift = float(np.mean(np.abs(fitted[matched, 0]-previous_aligned[matched])))
                    alpha = self.config.temporal_alpha
                    if shift > self.config.maximum_temporal_shift_px:
                        alpha *= .25; confidence *= .7
                        components["temporal_score"] = .3; rejections["TEMPORAL_REJECT"] += 1
                    fitted[:, 0] = alpha*fitted[:, 0] + (1-alpha)*previous_aligned
            self.previous = fitted.copy(); self.previous_confidence = confidence; self.fallback_age = 0
            state = (VALID if len(fitted) >= self.config.valid_min_points and
                     both_ratio >= self.config.valid_min_both_ratio and
                     confidence >= self.config.valid_min_confidence else DEGRADED)
            diagnostics["final_path_points"] = len(fitted)
            result = PathResult(fitted, sources, confidence, state, True, 0.0,
                                component, left, right, raw, diagnostics, components)
        elif self.previous is not None and self.fallback_age < self.config.max_temporal_fallback_frames:
            self.fallback_age += 1
            confidence = self.previous_confidence * self.config.temporal_weight * (
                1-self.fallback_age/(self.config.max_temporal_fallback_frames+1))
            result = PathResult(self.previous.copy(), [TEMPORAL_FALLBACK]*len(self.previous),
                                confidence, DEGRADED, True, 0.0, component,
                                left, right, raw, diagnostics, components)
        else:
            self.fallback_age += 1
            empty = np.empty((0, 2), float)
            result = PathResult(empty, [], 0.0, INVALID, False, 0.0,
                                component, left, right, raw, diagnostics, components)
        result.diagnostics["final_path_points"] = len(result.points)
        result.latency_ms = (time.perf_counter()-started)*1000.0
        return result
