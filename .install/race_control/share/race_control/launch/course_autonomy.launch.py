import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, LogInfo
from launch.launch_description_sources import PythonLaunchDescriptionSource


def include(package, launch_file, arguments=None):
    return IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory(package), "launch", launch_file)
        ),
        launch_arguments=(arguments or {}).items(),
    )


def generate_launch_description():
    return LaunchDescription([
        LogInfo(msg=("13-section camera/Depth/IMU mission decision enabled. "
                     "This launch does not arm or start the Arduino bridge.")),
        include("race_control", "camera_pure_pursuit.launch.py", {"commanded_speed_mps": "0.0"}),
        include("race_control", "course_mission.launch.py"),
    ])
