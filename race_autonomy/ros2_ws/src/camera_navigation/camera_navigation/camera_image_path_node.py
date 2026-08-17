"""ROS adapter for synchronized semantic masks and image-space paths."""
import json
import time
from collections import OrderedDict, deque

import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from rclpy.qos import (QoSDurabilityPolicy, QoSHistoryPolicy, QoSProfile,
                       QoSReliabilityPolicy, qos_profile_sensor_data)
from sensor_msgs.msg import Image
from std_msgs.msg import Bool, Float32, Int8, String
from race_interfaces.msg import ImagePath, ImagePathPoint, SemanticPathFrame
from .semantic_path_contract import decode_binary_rle
from .unique_frame_rates import UniqueFrameRates
from .overlay_worker import LatestOnlyWorker, OverlayRateLimiter


def path_computation_enabled(control_mode, visualization_only):
    return int(control_mode) == 1 or bool(visualization_only)

from .image_path_planner import (ImagePathPlanner, PlannerConfig, INACTIVE,
                                 BOTH_BOUNDARIES, LEFT_BOUNDARY, RIGHT_BOUNDARY,
                                 ROAD_CENTER, TEMPORAL_FALLBACK)


class CameraImagePathNode(Node):
    def __init__(self):
        super().__init__("camera_image_path_node")
        defaults = {
            "vehicle_center_x_px": 320.0,
            "roi_top": 120, "roi_bottom": 475, "sample_interval_px": 10,
            "sample_band_half_height_px": 2, "seed_half_width_px": 80,
            "seed_height_px": 24, "minimum_component_pixels": 20,
            "maximum_lateral_jump_px": 90.0, "road_containment_tolerance_px": 8,
            "exclusion_overlap_ratio": 0.35, "polynomial_degree": 2,
            "temporal_alpha": 0.35, "maximum_temporal_shift_px": 55.0,
            "max_temporal_fallback_frames": 5, "both_weight": 1.0,
            "single_weight": 0.72, "road_weight": 0.48, "temporal_weight": 0.25,
            "valid_min_points": 8, "valid_min_both_ratio": 0.55,
            "valid_min_confidence": 0.55,
            "semantic_path_frame_topic": "/perception/semantic_path_frame",
            "control_mode_topic": "/mission/control_mode",
            "visualization_only": False,
            "input_image_topic": "/camera/image_raw",
            "path_overlay_max_fps": 45.0,
        }
        for name, value in defaults.items(): self.declare_parameter(name, value)
        config_names = [name for name in defaults if name not in
                        ("semantic_path_frame_topic", "control_mode_topic",
                         "visualization_only", "input_image_topic",
                         "path_overlay_max_fps")]
        self.planner = ImagePathPlanner(PlannerConfig(**{name: self.get_parameter(name).value for name in config_names}))
        self.control_mode = 0
        self.latencies = deque(maxlen=300)
        self.processing_latencies = deque(maxlen=300); self.frame_count = 0
        self.overlay_latencies = deque(maxlen=300)
        self.overlay_missing_rgb = 0
        self.started = None
        self.received_count = 0; self.accepted_count = 0; self.published_count = 0
        self.duplicate_count = 0; self.stale_count = 0
        self.last_processed_stamp = None; self.last_near = None
        self.rates = UniqueFrameRates(); self.rgb_cache = OrderedDict(); self.upstream_fps = {}
        self.create_subscription(SemanticPathFrame, self.get_parameter("semantic_path_frame_topic").value,
                                 self.on_semantic_frame, 10)
        self.create_subscription(Int8, self.get_parameter("control_mode_topic").value,
                                 self.on_control_mode, 10)
        if float(self.get_parameter("path_overlay_max_fps").value) <= 0.0:
            raise ValueError("path_overlay_max_fps must be positive")
        self._rgb_subscription = None
        self.create_subscription(String, "/camera/realtime_fps", self.on_upstream_fps, 10)
        self.typed_path_pub = self.create_publisher(ImagePath, "/camera/image_path_typed", 10)
        self.path_pub = self.create_publisher(String, "/camera/image_path", 10)
        self.valid_pub = self.create_publisher(Bool, "/camera/image_path_valid", 10)
        self.confidence_pub = self.create_publisher(Float32, "/camera/image_path_confidence", 10)
        self.state_pub = self.create_publisher(String, "/camera/image_path_state", 10)
        self.owner_pub = self.create_publisher(String, "/camera/path_ownership", 10)
        # Canonical scalar-health aliases consumed by autonomy_output_node /
        # course_mission_node / camera_path_controller_node. These carry real,
        # non-fabricated signals (validity/confidence/mode derived from the same
        # result as /camera/image_path_*); they do NOT imply a metric geometric
        # /camera/path (nav_msgs/Path) exists — see camera_pure_pursuit.launch.py
        # for why that leg is intentionally left unwired pending calibration.
        self.canonical_valid_pub = self.create_publisher(Bool, "/camera/path_valid", 10)
        self.canonical_confidence_pub = self.create_publisher(Float32, "/camera/path_confidence", 10)
        self.canonical_mode_pub = self.create_publisher(Int8, "/camera/path_mode", 10)
        self.debug_pub = self.create_publisher(Image, "/camera/path_debug_image", 2)
        overlay_qos = QoSProfile(history=QoSHistoryPolicy.KEEP_LAST, depth=1,
                                 reliability=QoSReliabilityPolicy.BEST_EFFORT,
                                 durability=QoSDurabilityPolicy.VOLATILE)
        self.overlay_pub = self.create_publisher(
            Image, "/camera/path_overlay_image", overlay_qos)
        self.metrics_pub = self.create_publisher(String, "/camera/path_metrics", 10)
        self.realtime_pub = self.create_publisher(String, "/camera/path_realtime_fps", 10)
        self.overlay_limiter = OverlayRateLimiter(
            self.get_parameter("path_overlay_max_fps").value)
        self.overlay_worker = LatestOnlyWorker(
            self._publish_path_overlay, "path-overlay")
        self.create_timer(1.0, self.publish_realtime_fps)
        self.create_timer(0.25, self._update_overlay_subscription)

    def on_control_mode(self, message):
        self.control_mode = int(message.data)
        if self.control_mode != 1:
            self.planner.reset()

    def on_rgb(self, message):
        key = int(message.header.stamp.sec)*1_000_000_000 + int(message.header.stamp.nanosec)
        self.rgb_cache[key] = message
        while len(self.rgb_cache) > 20: self.rgb_cache.popitem(last=False)

    def _update_overlay_subscription(self):
        subscribed = self.overlay_pub.get_subscription_count() > 0
        if subscribed and self._rgb_subscription is None:
            self._rgb_subscription = self.create_subscription(
                Image, self.get_parameter("input_image_topic").value,
                self.on_rgb, qos_profile_sensor_data)
        elif not subscribed and self._rgb_subscription is not None:
            self.destroy_subscription(self._rgb_subscription)
            self._rgb_subscription = None
            self.rgb_cache.clear()
            self.overlay_worker.clear()
            self.overlay_limiter.reset()

    def on_upstream_fps(self, message):
        try: self.upstream_fps = json.loads(message.data)
        except (ValueError, TypeError): self.upstream_fps = {}

    def on_semantic_frame(self, message):
        callback_started = time.perf_counter()
        self.received_count += 1
        key = int(message.header.stamp.sec)*1_000_000_000 + int(message.header.stamp.nanosec)
        if self.last_processed_stamp is not None:
            if key == self.last_processed_stamp: self.duplicate_count += 1; return
            if key < self.last_processed_stamp: self.stale_count += 1; return
        self.last_processed_stamp = key
        self.accepted_count += 1
        self.rates.mark("semantic_received", message.header.stamp.sec,
                        message.header.stamp.nanosec)
        height, width = int(message.image_height), int(message.image_width)
        decode_started = time.perf_counter()
        masks = [decode_binary_rle(values, height, width) for values in
                 (message.road_rle, message.lane_rle, message.words_rle,
                  message.stop_line_rle, message.c_line_rle)]
        decode_ms = (time.perf_counter()-decode_started)*1000.0
        self._current_rgb_message = self.rgb_cache.get(key)
        self._path_callback_started = callback_started
        self.process(message, masks, decode_ms)

    def process(self, semantic_message, masks, decode_ms):
        callback_started = getattr(
            self, "_path_callback_started", time.perf_counter())
        rgb_message = getattr(self, "_current_rgb_message", None)
        if self.started is None: self.started = time.monotonic()
        road, lane, words, stop, c_line = masks
        compute_enabled = path_computation_enabled(
            self.control_mode, self.get_parameter("visualization_only").value)
        if not compute_enabled:
            result = self.planner.inactive(road.shape); owner = "GPS_PATH_OWNER"
        else:
            result = self.planner.plan(road, lane, np.zeros_like(lane), words, stop, c_line)
            owner = "CAMERA_PATH_OWNER" if self.control_mode == 1 else "GPS_PATH_OWNER"
        self.frame_count += 1; self.latencies.append(result.latency_ms)
        self.rates.mark("path_processed", semantic_message.header.stamp.sec,
                        semantic_message.header.stamp.nanosec)
        points = [{"x_px": float(x), "y_px": float(y),
                   "x_norm": float(x/road.shape[1]), "y_norm": float(y/road.shape[0]),
                   "source": result.sources[i] if i < len(result.sources) else "UNKNOWN"}
                  for i, (x, y) in enumerate(result.points)]
        payload = {"header": {"stamp": {"sec": semantic_message.header.stamp.sec,
                                          "nanosec": semantic_message.header.stamp.nanosec},
                               "frame_id": semantic_message.header.frame_id},
                   "coordinate_frame": "IMAGE_PIXELS", "image_width": road.shape[1],
                   "image_height": road.shape[0], "path_valid": result.valid,
                   "path_confidence": result.confidence, "path_state": result.state,
                   "ownership": owner, "control_mode": self.control_mode, "points": points}
        self.typed_path_pub.publish(self.typed_message(semantic_message, result, owner))
        self.path_pub.publish(String(data=json.dumps(payload, separators=(",", ":"))))
        self.valid_pub.publish(Bool(data=result.valid)); self.confidence_pub.publish(Float32(data=result.confidence))
        self.state_pub.publish(String(data=result.state)); self.owner_pub.publish(String(data=owner))
        state_mode = {"INACTIVE": 0, "INVALID": 1, "DEGRADED": 2, "VALID": 3}.get(result.state, 0)
        self.canonical_valid_pub.publish(Bool(data=result.valid))
        self.canonical_confidence_pub.publish(Float32(data=result.confidence))
        self.canonical_mode_pub.publish(Int8(data=state_mode))
        self.published_count += 1
        self.rates.mark("path_published", semantic_message.header.stamp.sec,
                        semantic_message.header.stamp.nanosec)
        metrics = self.metrics(result, owner); metrics["semantic_decode_ms"] = decode_ms
        metrics["candidate_survival"] = result.diagnostics
        metrics["confidence_components"] = result.confidence_components
        metrics["semantic_encoded_bytes"] = int(semantic_message.encoded_bytes)
        metrics["semantic_uncompressed_bytes"] = int(semantic_message.uncompressed_bytes)
        self.metrics_pub.publish(String(data=json.dumps(metrics, separators=(",", ":"))))
        self.processing_latencies.append(
            (time.perf_counter()-callback_started)*1000.0)
        # Debug rendering and 640x480 byte serialization are intentionally lazy;
        # RQT enables them simply by subscribing without taxing normal driving.
        if self.debug_pub.get_subscription_count() > 0:
            self.debug_pub.publish(self.debug_image(semantic_message, result, owner, masks[2:]))
        if self.overlay_pub.get_subscription_count() > 0 and rgb_message is None:
            self.overlay_missing_rgb += 1
        if (self.overlay_pub.get_subscription_count() > 0 and rgb_message is not None and
                self.overlay_limiter.ready(time.monotonic())):
            # Exact-stamp source/result references enter a one-slot worker.
            # Rendering and Image serialization never block path publication.
            self.overlay_worker.submit((rgb_message, result))

    @staticmethod
    def typed_message(source, result, owner):
        message = ImagePath(); message.header = source.header
        message.image_width = source.image_width; message.image_height = source.image_height
        message.path_valid = result.valid; message.path_confidence = result.confidence
        message.path_state = {"INVALID": ImagePath.STATE_INVALID, "VALID": ImagePath.STATE_VALID,
                              "DEGRADED": ImagePath.STATE_DEGRADED,
                              "INACTIVE": ImagePath.STATE_INACTIVE}[result.state]
        message.ownership = (ImagePath.OWNER_CAMERA if owner == "CAMERA_PATH_OWNER"
                             else ImagePath.OWNER_GPS)
        source_codes = {BOTH_BOUNDARIES: ImagePathPoint.BOTH_BOUNDARIES,
                        LEFT_BOUNDARY: ImagePathPoint.LEFT_BOUNDARY,
                        RIGHT_BOUNDARY: ImagePathPoint.RIGHT_BOUNDARY,
                        ROAD_CENTER: ImagePathPoint.ROAD_CENTER,
                        TEMPORAL_FALLBACK: ImagePathPoint.TEMPORAL_FALLBACK}
        for index, (x, y) in enumerate(result.points):
            point = ImagePathPoint(x_px=float(x), y_px=float(y),
                                   x_norm=float(x/source.image_width),
                                   y_norm=float(y/source.image_height),
                                   confidence=float(result.confidence),
                                   source=source_codes[result.sources[index]])
            message.points.append(point)
        return message

    def publish_realtime_fps(self):
        path_rates=self.rates.snapshot("path_published")
        processed_rates=self.rates.snapshot("path_processed")
        overlay_rates=self.rates.snapshot("overlay_published")
        processing=np.asarray(self.processing_latencies,dtype=float)
        overlay_processing=np.asarray(self.overlay_latencies,dtype=float)
        processing_summary=(
            {"count":int(processing.size),
             "p50":float(np.percentile(processing,50)),
             "p95":float(np.percentile(processing,95)),
             "max":float(processing.max())}
            if processing.size else {"count":0,"p50":0.0,"p95":0.0,"max":0.0})
        document={"semantic_received":self.rates.snapshot("semantic_received"),
                  "path_processed":processed_rates,
                  "path_published":path_rates,
                  "overlay_published":overlay_rates,
                  "path_unique_fps":path_rates,
                  "path_overlay_fps":overlay_rates,
                  "received_count":self.received_count,
                  "accepted_count":self.accepted_count,
                  "processed_count":self.frame_count,
                  "published_count":self.published_count,"stale":self.stale_count,
                  "duplicate":self.duplicate_count,
                  "backlog":max(0,self.accepted_count-self.frame_count),
                  "path_processing_ms":processing_summary,
                  "overlay_worker":self.overlay_worker.snapshot(),
                  "overlay_missing_rgb":self.overlay_missing_rgb,
                  "overlay_render_ms":({"count":int(overlay_processing.size),
                      "p50":float(np.percentile(overlay_processing,50)),
                      "p95":float(np.percentile(overlay_processing,95)),
                      "max":float(overlay_processing.max())} if overlay_processing.size
                      else {"count":0,"p50":0.0,"p95":0.0,"max":0.0}),
                  "mission_owner":"CAMERA" if self.control_mode==1 else "GPS",
                  "path_computation_enabled":path_computation_enabled(
                      self.control_mode,self.get_parameter("visualization_only").value),
                  "vehicle_command_enabled":False}
        self.realtime_pub.publish(String(data=json.dumps(document,separators=(",",":"))))

    def overlay_image(self, source, result):
        raw=np.frombuffer(source.data,np.uint8).reshape(source.height,source.step)[:,:source.width*3]
        image=np.ascontiguousarray(raw.reshape(source.height,source.width,3))
        if source.encoding.lower()=="rgb8": image=cv2.cvtColor(image,cv2.COLOR_RGB2BGR)
        else: image=image.copy()
        if len(result.points)>1:
            pts=np.rint(result.points).astype(np.int32).reshape(-1,1,2)
            cv2.polylines(image,[pts],False,(0,255,0),3,cv2.LINE_AA)
        upstream=self.upstream_fps
        def upstream_rate(stage):
            value=upstream.get(stage,{})
            if isinstance(value,dict): return float(value.get("5s",{}).get("header_fps",0.0))
            return float(value or 0.0)
        lines=[f"CAM  : {float(upstream.get('camera_input_fps_5s',0.0)):4.1f}",
               f"INF  : {upstream_rate('inference_unique_fps'):4.1f}",
               f"PATH : {self.rates.snapshot('path_published')['5s']['header_fps']:4.1f}",
               f"STATE: {result.state}"]
        for index,text in enumerate(lines):
            cv2.putText(image,text,(8,20+18*index),cv2.FONT_HERSHEY_SIMPLEX,.48,(0,255,0),2,cv2.LINE_AA)
        msg=Image();msg.header=source.header;msg.height=source.height;msg.width=source.width
        msg.encoding="bgr8";msg.is_bigendian=False;msg.step=source.width*3;msg.data=image.tobytes();return msg

    def _publish_path_overlay(self, job):
        if self.overlay_pub.get_subscription_count() == 0:
            return
        source, result = job
        started=time.perf_counter()
        try:
            self.overlay_pub.publish(self.overlay_image(source, result))
            self.rates.mark("overlay_published", source.header.stamp.sec,
                            source.header.stamp.nanosec)
            self.overlay_latencies.append((time.perf_counter()-started)*1000.0)
        except Exception as error:
            self.get_logger().error(f"Path overlay failed: {error}")

    def destroy_node(self):
        self.overlay_worker.close()
        return super().destroy_node()

    def metrics(self, result, owner):
        points = result.points
        near = float(points[0, 0]) if len(points) else None
        middle = float(points[len(points)//2, 0]) if len(points) else None
        far = float(points[-1, 0]) if len(points) else None
        heading = float(np.degrees(np.arctan2(points[-1, 0]-points[0, 0],
                                              max(1.0, points[0, 1]-points[-1, 1])))) if len(points)>1 else None
        curvature = float(np.max(np.abs(np.diff(points[:, 0], n=2)))) if len(points)>2 else None
        array = np.asarray(self.latencies)
        lateral_shift = None if near is None or self.last_near is None else near-self.last_near
        if near is not None: self.last_near = near
        return {"frame_count": self.frame_count,
                "received_count": self.received_count,
                "accepted_count": self.accepted_count,
                "processed_count": self.frame_count,
                "published_count": self.published_count,
                "processed_fps_observed": self.frame_count/max(1e-9, time.monotonic()-self.started),
                "path_valid": result.valid,
                "path_state": result.state, "path_confidence": result.confidence,
                "point_count": len(points), "near_x": near, "middle_x": middle,
                "far_x": far, "heading_deg": heading, "curvature_px": curvature,
                "lateral_shift_px": lateral_shift,
                "source_mode": max(set(result.sources), key=result.sources.count) if result.sources else "NONE",
                "ownership": owner, "latency_ms": result.latency_ms,
                "latency_mean_ms": float(array.mean()),
                "latency_p95_ms": float(np.percentile(array, 95)),
                "stale_count": self.stale_count, "duplicate_count": self.duplicate_count,
                "backlog_drop_count": max(0, self.accepted_count-self.frame_count)}

    def debug_image(self, source, result, owner, exclusions):
        road = result.road_component
        image = np.zeros((*road.shape, 3), np.uint8); image[road > 0] = (40, 70, 40)
        for mask, color in zip(exclusions, ((180, 60, 180), (0, 0, 255), (255, 80, 200))): image[mask > 0] = color
        for points, color in ((result.left, (255, 255, 255)), (result.right, (0, 255, 255)),
                              (result.raw, (255, 160, 0)), (result.points, (0, 255, 0))):
            for x, y in points: cv2.circle(image, (int(round(x)), int(round(y))), 3, color, -1)
        text = ("INTERSECTION | GPS PATH OWNER | CAMERA PATH INACTIVE" if result.state == INACTIVE
                else f"{result.state} conf={result.confidence:.2f} {owner}")
        cv2.putText(image, text, (8, 24), cv2.FONT_HERSHEY_SIMPLEX, .55, (255,255,255), 2, cv2.LINE_AA)
        message = Image(); message.header = source.header; message.height, message.width = image.shape[:2]
        message.encoding = "bgr8"; message.is_bigendian = False; message.step = message.width*3
        message.data = image.tobytes(); return message


def main(args=None):
    rclpy.init(args=args, signal_handler_options=SignalHandlerOptions.NO); node = CameraImagePathNode()
    try: rclpy.spin(node)
    except KeyboardInterrupt: pass
    finally:
        node.destroy_node()
        if rclpy.ok(): rclpy.shutdown()
