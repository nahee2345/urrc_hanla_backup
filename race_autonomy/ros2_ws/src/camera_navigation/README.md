# camera_navigation

The former projected-view planner, camera geometry, calibration playback, and
their launch paths were removed. No navigation node from this package is
started by the perception validation profile.

`camera_image_path_node` is the original-image-coordinate path generator. It
uses synchronized semantic masks directly in the 640x480 image plane. It does
not use projection, metric coordinates, or publish `nav_msgs/Path`.

The typed `/mission/control_mode` output from `course_mission_node` is the
single ownership contract. Mode 1 enables `CAMERA_PATH_OWNER`; every other
mode puts this node in `INACTIVE`. Intersection section membership is defined
once in `race_control/config/course_mission.yaml`, where mode 2 selects the
GPS/Nav2 lateral source or safe-stops if that source is unavailable.

The production hot-path input is one typed
`race_interfaces/SemanticPathFrame` on `/perception/semantic_path_frame`.
It carries lossless binary RLE for road, combined W/Y lane semantics, and the
words/stop-line/C-line exclusions from exactly one inference timestamp. Full
mask topics remain available for debug and other consumers. Outputs are:

- `/camera/image_path` (`std_msgs/String` JSON, explicitly `IMAGE_PIXELS`)
- `/camera/image_path_typed` (`race_interfaces/ImagePath`, production contract)
- `/camera/image_path_valid`, `/camera/image_path_confidence`,
  `/camera/image_path_state`
- `/camera/path_ownership`, `/camera/path_metrics`
- `/camera/path_debug_image`
- `/camera/path_overlay_image` (same-stamp RGB background plus final green path)

`visualization_only:=true` separates path computation from vehicle ownership:
GPS can remain the mission/control owner while camera pixel-path calculation
and the RQT overlay continue. This mode never publishes vehicle commands.

The canonical path overlay is subscriber-gated and defaults to 45 FPS through
`path_overlay_max_fps`. With no viewer, the node removes its raw RGB
subscription and performs no overlay image copy, drawing, conversion, or
publication. With a viewer, exact-stamp RGB/path pairs enter a latest-only
worker so visualization cannot hold up path publication.

The JSON contains pixel and normalized coordinates. It must not be connected
to a metric controller without a separately reviewed coordinate conversion.
