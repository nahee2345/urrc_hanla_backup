# D456 LOW-FPS ROOT CAUSE REPORT

Report time: 2026-08-15 (Asia/Seoul)

Status: **PARTIAL — blocked before Stage A because the D456 disconnected and is no longer enumerated.**

## Test Environment

- indoor/outdoor: not independently verified
- camera fixed: not independently verified
- cable fixed: contradicted by a whole-hub USB disconnect at 14:10:04
- AC/battery: battery (`/sys/class/power_supply/ACAD/online=0`)
- RQT: no RQT process running during diagnosis
- unnecessary applications: not modified

## Device

- serial: device-selection serial `338122302896`; ASIC/firmware-update ID `412243062984`
- firmware: supplied value `5.15.0.2`; not re-read because the device was absent
- USB type: boot log shows the D456 behind a GenesysLogic USB 3.1 hub
- active USB speed: none; device disconnected. Before disconnect, kernel enumeration was SuperSpeed.
- selected RGB profile: configured `640x480 RGB8 @ 60 FPS`; active profile not measured

## Permission

- video group: PASS — `qor` is in `video` in the real login session
- /dev/video permissions: existing Chicony nodes are `root:video 0660`; D456 nodes are absent
- udev: no installed `*realsense*` rule was found under `/etc/udev/rules.d` or `/lib/udev/rules.d`
- permission errors: none demonstrated for a connected D456; cannot validate while absent
- chmod 666 dependency: none on the currently present video nodes

## Host

- RAM: 30 GiB total, 15 GiB available at diagnosis
- swap: 8 GiB total, 0 B used
- vmstat si/so: 0/0 in the sampled interval
- CPU: Intel Core Ultra 9 275HX, 24 CPUs
- GPU: NVIDIA GeForce RTX 5060 Laptop GPU, driver 595.84, CUDA 13.2; idle at diagnosis
- power mode: `balanced`, running on battery

Host memory pressure is **not** a demonstrated root cause in this sample.

## Stage A - librealsense only

- FPS: not measured — `rs-enumerate-devices` returned `No device detected`
- p95 interval: not measured
- max gap: not measured

## Stage B - ROS D456 only

- camera 1s: not measured
- camera 5s: not measured
- camera 10s: not measured

## Stage C - +TensorRT

- received: not measured
- inference: not measured
- semantic: not measured
- preprocessing p95: not measured
- inference p95: not measured
- postprocess p95: not measured

## Stage D - +Path

- semantic receive: not measured
- path: not measured
- path processing p95: not measured

## Stage E - +RQT overlay

- path: not measured
- overlay: not measured
- effect of RQT: not measured

## USB Kernel Events

- disconnect: yes. At 14:10:04, `usb 4-1` (GenesysLogic USB 3.1 hub) and child `usb 4-1.1` (D456) disconnected. A paired USB 2.1 hub and Arduino also disconnected at the same timestamp.
- reset: no D456 reset was found in the inspected boot-to-diagnosis log
- UVC error: boot-time UVC format/non-compliance messages exist; no sustained-stream correlation was measured
- timestamp correlation with FPS drop: unavailable because no simultaneous FPS trace exists

The simultaneous parent-hub and child-device disconnect is direct evidence of a physical USB path, hub, connector, cable, or hub-power interruption. It does not by itself prove that every earlier low-FPS event had the same cause.

## Motion Reproduction

- fixed: not measured
- camera moved: not measured
- cable moved: not measured
- full system moved: not measured

## Root Cause

CASE classification: **not yet classifiable (pre-Stage-A blocker)**. The available evidence is consistent with CASE B/F physical-path risk, but the required fixed/motion and vehicle comparisons have not run.

PRIMARY ROOT CAUSE:

- Current test blocker/device loss: the shared external USB hub path disconnected as a unit at 14:10:04. The D456 is currently absent from both `lsusb` and librealsense discovery.
- Historical sustained 4–7 FPS: **not proven with the available timestamped evidence**.

SECONDARY CONTRIBUTOR:

- Production configuration used ASIC/firmware-update ID `412243062984` as the device serial in four runtime defaults. This deterministically causes device-selection failure when the camera is present.
- Test conditions were not production-ready: D456 was behind a hub, AC was disconnected, and the host used the balanced power profile.
- Standard installed RealSense udev-rule presence could not be confirmed; no matching installed rule was found.

NOT ROOT CAUSE:

- Swap thrashing in this sample: swap usage and vmstat `si/so` were zero.
- TensorRT, semantic processing, path processing, QoS, executor, auto exposure, and RQT: not tested and therefore neither blamed nor cleared.

## Fix

- Replaced all runtime D456 defaults with device serial `338122302896`:
  - `camera_bringup/config/d456.yaml`
  - `camera_bringup/launch/d456_bringup.launch.py`
  - `camera_bringup/launch/d456_production.launch.py`
  - `camera_yolo_inference/launch/d456_yolo_perception.launch.py`
- Corrected the camera bring-up documentation and explicitly distinguished the device serial from the ASIC/update ID.
- Added a regression test that rejects the ASIC ID in runtime defaults.
- No FPS, QoS, executor, frame-skipping, sleep, duplicate-publish, or algorithm changes were made without measurements.

Required physical remediation before resuming:

1. Connect the D456 directly to the laptop's USB 3.x port with the known-good USB 3 cable; do not use the observed GenesysLogic hub.
2. Secure both connectors and cable, connect AC power, and keep RQT off.
3. Confirm `lsusb -t` reports the D456 at `5000M` or faster and `rs-enumerate-devices -s` reports device serial `338122302896`.
4. Verify the recreated D456 `/dev/video*` nodes are `root:video` with group read/write access and inspect their ACLs.
5. Evaluate the vendor RealSense udev rules for this installed librealsense package; do not install the repository's broad custom IIO rule blindly.
6. Only then resume Stage A for 60 seconds, followed by Stages B–E in order.

## Performance After Fix

30 seconds or longer: not measured because the camera is disconnected.

- camera: not measured
- received: not measured
- inference: not measured
- semantic: not measured
- path: not measured
- overlay: not measured
- minimum 5s FPS: not measured
- minimum 10s FPS: not measured
- input→path retention: not measured

## Regression

- build: PASS — `colcon build --symlink-install`, 9 packages
- new targeted test: PASS — 1 test
- package-isolated pytest: PASS — 245 tests total
- `colcon test`: infrastructure PARTIAL — six pre-existing Python packages reported `NO TESTS RAN` (exit 5); camera_bringup ran successfully
- `colcon test-result --verbose`: 2 tests, 0 errors, 0 failures

## Final

CAMERA >=30 FPS SUSTAINED: **PARTIAL — not measured**

PERCEPTION >=30 FPS: **PARTIAL — not measured**

PATH >=30 FPS: **PARTIAL — not measured**

TARGET >=80% OF 60FPS: **PARTIAL — not measured**

No performance PASS is claimed without a connected camera and a 30–60 second sustained measurement.

## Follow-up isolation attempt — 2026-08-15

The D456 was reconnected directly and the host reported:

- D456 present as USB `8086:0b5c`
- `/dev/video0` through `/dev/video5` recreated as `root:video 0660`
- all D456 video/HID interfaces attached directly at `5000M`
- no TensorRT/path/RQT stage was intentionally started

Before launching ROS, `rs-enumerate-devices -s` failed to return. A 15-second
`timeout` also failed to recover the command promptly. Subsequent escalated
host-command probes were blocked behind the stalled host operation. This is a
pre-ROS librealsense/USB-control-path stall, not evidence of a TensorRT or path
bottleneck.

Stage A/B FPS collection was deliberately not started on top of this abnormal
state. The next safe step is to unplug the D456, wait at least five seconds,
reconnect it directly, and confirm that a time-bounded `rs-enumerate-devices -s`
returns before launching `realsense2_camera`. If unplugging does not release the
stalled process/USB control path, reboot the host before continuing the 60-second
D456-only measurement.
