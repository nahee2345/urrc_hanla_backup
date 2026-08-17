# TWO-VIEW RQT VALIDATION REPORT

Report time: 2026-08-15 (Asia/Seoul)

## Perception View

- topic: `/camera/perception_overlay_image`
- background: exact-stamp `/camera/image_raw` D456 RGB frame
- semantic classes: `road`, `W_line`, `Y_line`, `R_light`, `Y_light`,
  `G_light`, `Left`, `etc_light`, `stop`, `traffic20`, `C_line`, `words`
- stop-line distinguishable: implemented and synthetic-image verified; the
  model's separate `stop` class uses its existing magenta color, active legend,
  and `STOP: YES/NO`, distinct from outlined white `W_line`
- road-text distinguishable: implemented and synthetic-image verified through
  the existing purple `words` class and active legend
- overlay FPS: configurable; default maximum 45 FPS, independently rate-limited
  from inference

The class names and BGR colors come from the existing model metadata,
`class_manifest.yaml`, and `debug_renderer.py`; no new semantic class was
invented.

## Path View

- topic: `/camera/path_overlay_image`
- background: exact-stamp `/camera/image_raw` D456 RGB frame
- centerline color: BGR `(0, 255, 0)`
- path state: compact `STATE: VALID/DEGRADED/INVALID/INACTIVE`
- overlay FPS: configurable; default maximum 45 FPS, independently rate-limited
  from path processing

The canonical path view contains only CAM/INF/PATH/STATE text and the final
green centerline. Candidate lines, masks, components, raw midpoints, fitting
controls, and confidence details remain confined to the development debug
topic.

## RQT Layout

- number of image views: exactly 2 in `two_view_rqt.launch.py`
- topics:
  - `/camera/perception_overlay_image`
  - `/camera/path_overlay_image`

Production keeps `launch_rqt:=false`. When enabled, the two canonical topics
are selected automatically in two standalone Image View windows. The current
environment had no GUI validation opportunity; left/right window tiling remains
window-manager placement rather than a verified saved perspective.

## Subscriber Gating

- perception render with no subscriber: disabled before worker submission; no
  overlay copy, blend, drawing, output conversion, or publication
- path render with no subscriber: disabled; its raw RGB subscription is also
  destroyed and the exact-stamp cache and pending worker slot are cleared

Both canonical branches use an asynchronous worker with a single replaceable
pending slot. Rendering or DDS publication cannot hold up inference/semantic or
path publication, and slow visualization does not accumulate a frame queue.

The existing `/perception/detections_image` and `/camera/path_debug_image`
remain subscriber-gated development topics and are not opened by the two-view
launch.

## Performance

The latest sysfs check found the D456 directly at USB path `4-2`, speed
`5000M`, with AC power connected. However, the privileged host execution path
remained blocked after the earlier librealsense/libusb enumeration stall: even
a process-list probe did not return within 30 seconds. The stack could not be
started safely without first confirming that no stale camera process owned the
device. No hardware FPS number is fabricated.

### RQT OFF

- CAM: not measured
- INF: not measured
- SEM: not measured
- PATH: not measured

### PERCEPTION ONLY

- CAM: not measured
- INF: not measured
- SEM: not measured
- PATH: not measured

### PATH ONLY

- CAM: not measured
- INF: not measured
- SEM: not measured
- PATH: not measured

### BOTH

- CAM: not measured
- INF: not measured
- SEM: not measured
- PATH: not measured

## Performance Loss

- two-view path FPS loss: not measured

## Tests

- build: PASS — `colcon build --symlink-install`, 9 packages
- pytest: PASS — 253 package-isolated tests
- launch loading: PASS — production and two-view launch argument inspection
- synthetic rendering: PASS — perception identity/status/legend and path RGB /
  green-centerline/minimal-text contracts visually inspected
- lint: PARTIAL — critical Python lint (`E9,F63,F7,F82`) passes. The repository's
  full flake8 profile reports extensive pre-existing formatting/docstring/quote
  violations in the compact legacy sources, so a full-style PASS is not claimed.

## Final

PERCEPTION VISUALLY VERIFIABLE: **PARTIAL** — renderer verified synthetically;
the eight requested physical targets were not presented to a connected D456

PATH VISUALLY VERIFIABLE: **PARTIAL** — renderer verified synthetically; the
seven requested real road situations were not available

PRODUCTION >=30 FPS: **PARTIAL — not measured**

RQT PERFORMANCE IMPACT <=5%: **PARTIAL — not measured**

## 45 FPS Target Update

The production debug defaults are now:

- `perception_overlay_max_fps: 45.0`
- `path_overlay_max_fps: 45.0`

The gating, exact-stamp matching, one-slot latest-only workers, asynchronous
rendering, and non-blocking production callbacks are unchanged. Diagnostics
keep separate event streams and fields for camera input, inference, semantic,
production path, perception overlay, and path overlay.

### RQT OFF

- CAM: not measured
- INF: not measured
- SEM: not measured
- PATH: not measured

### RQT BOTH ON

- CAM: not measured
- INF: not measured
- SEM: not measured
- PATH: not measured
- PERCEPTION OVERLAY: not measured
- PATH OVERLAY: not measured

### Latest Final Assessment

D456 >=55 FPS: **PARTIAL — connected at 5000M, sustained FPS not measured**

PRODUCTION >=45 FPS: **PARTIAL — not measured**

RQT TWO VIEW >=45 FPS: **PARTIAL — not measured**
