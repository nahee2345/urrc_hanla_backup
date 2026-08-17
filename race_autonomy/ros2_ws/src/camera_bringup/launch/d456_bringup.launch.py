"""Start one RealSense D456 node with production RGB and motion streams.

The production parameter file enables 640x480x60 RGB, 200 Hz gyro, and
100 Hz accel. Depth, infrared, pointcloud, alignment, sync, and RGBD remain
disabled."""

from pathlib import Path

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo, OpaqueFunction, Shutdown
from launch.event_handlers import OnProcessExit
from launch.actions import RegisterEventHandler
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def _positive_integer(name, value):
    try:
        parsed = int(value)
    except ValueError as error:
        raise RuntimeError(f"{name} must be a positive integer, got {value!r}") from error
    if parsed <= 0:
        raise RuntimeError(f"{name} must be a positive integer, got {value!r}")
    return parsed


def _launch_setup(context):
    serial_no = LaunchConfiguration("serial_no").perform(context).strip()
    if not serial_no:
        raise RuntimeError("serial_no must not be empty")

    width = _positive_integer("color_width", LaunchConfiguration("color_width").perform(context))
    height = _positive_integer("color_height", LaunchConfiguration("color_height").perform(context))
    fps = _positive_integer("color_fps", LaunchConfiguration("color_fps").perform(context))
    profile = f"{width}x{height}x{fps}"

    config_file = Path(get_package_share_directory("camera_bringup")) / "config" / "d456.yaml"
    if not config_file.is_file():
        raise RuntimeError(f"RealSense parameter file not found: {config_file}")

    camera = Node(
        package="realsense2_camera",
        executable="realsense2_camera_node",
        namespace="camera",
        name="camera",
        output="screen",
        emulate_tty=True,
        parameters=[
            str(config_file),
            {
                "serial_no": serial_no,
                "rgb_camera.color_profile": profile,
            },
        ],
        remappings=[
            ("/camera/camera/color/image_raw", "/camera/image_raw"),
            ("/camera/camera/color/camera_info", "/camera/camera_info"),
        ],
        arguments=["--ros-args", "--log-level", "info"],
    )

    return [
        LogInfo(msg=f"D456 serial: {serial_no}"),
        LogInfo(msg=f"RGB profile: {profile}, format: RGB8, auto exposure/gain: enabled"),
        LogInfo(msg=("Production mode: RGB 640x480 plus gyro=200 Hz and accel=100 Hz; "
                     "depth/infra/pointcloud/align/sync/rgbd disabled. "
                     "Outputs include /camera/image_raw and D456 motion samples")),
        LogInfo(msg=f"Parameters: {config_file}"),
        camera,
        RegisterEventHandler(
            OnProcessExit(
                target_action=camera,
                on_exit=[Shutdown(reason="RealSense camera node exited")],
            )
        ),
    ]


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            "serial_no",
            default_value="338122302896",
            description="D456 serial number",
        ),
        DeclareLaunchArgument(
            "color_width",
            default_value="640",
            description="RGB image width in pixels",
        ),
        DeclareLaunchArgument(
            "color_height",
            default_value="480",
            description="RGB image height in pixels",
        ),
        DeclareLaunchArgument(
            "color_fps",
            default_value="60",
            description="RGB frames per second (D456 supports 60 Hz at 640x480)",
        ),
        OpaqueFunction(function=_launch_setup),
    ])
