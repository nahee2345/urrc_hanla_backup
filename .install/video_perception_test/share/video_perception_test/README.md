# Saved-video perception validation

This disposable ROS package substitutes a saved MP4 for the D456 image source.
It does not contain inference, navigation, path generation, decisions, or
vehicle control. Deleting this entire directory does not affect production
packages.

`CameraInfo` published here is explicitly **TEST / NOT CALIBRATED**. It exists
only because the production inference node validates the image/header contract;
its values must never be used for geometry.

The original MP4 remains unchanged. The default input is
`input/test_video.mp4` (3840×2160, approximately 59.94 FPS). Each decoded frame
is resized in memory to 640×480 immediately before ROS message creation and is
published on a fixed 30 FPS schedule. No resized MP4 is created.

Build this isolated tool after sourcing the production workspace:

```bash
source /opt/ros/jazzy/setup.bash
source /home/qor/urrc_hanla/race_autonomy/ros2_ws/install/setup.bash
cd /home/qor/urrc_hanla
colcon build --symlink-install --base-paths video_perception_test \
  --build-base video_perception_test/.build \
  --install-base video_perception_test/.install \
  --log-base video_perception_test/.log
source video_perception_test/.install/setup.bash
ros2 launch video_perception_test video_perception_test.launch.py launch_rqt:=true
```

The saved-video launch pairs RELIABLE depth-one QoS on `/camera/image_raw` to
avoid local large-sample loss. Real-camera launch defaults remain sensor-data
BEST_EFFORT. With RQT enabled, `original_debug_stride:=2` keeps the reference
view near 15 FPS so the actual inference/overlay stream can sustain 30 FPS.
The recorder remains disabled by default.

Useful arguments include `video_path`, `playback_rate`, `loop`, `start_frame`,
`frame_id`, `publish_original_debug`, `save_annotated_video`, and
`launch_rqt`. If the source resolution changes, also pass
`expected_image_width` and `expected_image_height`.

RQT comparison topics:

- `/video_test/original_image`
- `/perception/detections_image`

Metadata is written as JSONL to `output/perception_results.jsonl`; the compact
performance summary is `output/performance_summary.json`. Annotated MP4 output
is disabled by default.
