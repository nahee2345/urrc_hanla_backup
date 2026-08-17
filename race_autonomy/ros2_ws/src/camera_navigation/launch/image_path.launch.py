from pathlib import Path

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    config = str(Path(get_package_share_directory("camera_navigation"))/"config"/"image_path.yaml")
    return LaunchDescription([
        # Execution-layer override only (planner/algorithm unchanged). Default
        # stays "false" (config-file behavior unchanged); pass
        # visualization_only:=true to compute paths without a
        # /mission/control_mode publisher (e.g. mission nodes removed / camera
        # standalone testing), matching path_computation_enabled() in
        # camera_image_path_node.py.
        DeclareLaunchArgument("visualization_only", default_value="false"),
        Node(package="camera_navigation", executable="camera_image_path_node",
             name="camera_image_path_node", output="screen",
             parameters=[config, {
                 "visualization_only": LaunchConfiguration("visualization_only"),
             }]),
    ])
