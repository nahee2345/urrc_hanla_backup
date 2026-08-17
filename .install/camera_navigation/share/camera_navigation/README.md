# camera_navigation

The former projected-view planner, camera geometry, calibration playback, and
their launch paths were removed. No navigation node from this package is
started by the perception validation profile.

Pure path-validation, path-shaping, speed-planning, and controller utilities
remain unchanged for later review. They are not a usable camera autonomy
pipeline without a newly designed original-image-coordinate path generator.
