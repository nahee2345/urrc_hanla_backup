"""Manually armed camera steering plus forward stage-1-only test."""
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, LogInfo
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node


# Measured stage 3 speed is 2.98 km/h. The current firmware uses three
# discrete forward stages, so the provisional linear stage-1 target is one
# third of that measured speed. Both downstream gates still clamp to stage 1.
STAGE_3_SPEED_KPH = 2.98
LOW_SPEED_STAGE_1_MPS = (STAGE_3_SPEED_KPH / 3.6) / 3.0


def generate_launch_description():
    control_share=get_package_share_directory("race_control")
    vehicle_share=get_package_share_directory("race_vehicle_interface")
    autonomy=IncludeLaunchDescription(PythonLaunchDescriptionSource(
        os.path.join(control_share,"launch","camera_pure_pursuit.launch.py")),
        launch_arguments={
            "commanded_speed_mps": f"{LOW_SPEED_STAGE_1_MPS:.7f}",
        }.items())
    bridge=Node(package="race_vehicle_interface",executable="arduino_serial_bridge_node",
        name="arduino_serial_bridge_node",output="screen",parameters=[
            os.path.join(vehicle_share,"config","arduino_bridge.yaml"),
            {"allow_transmit":True,"steering_only":False,"maximum_abs_stage":1}])
    interface=Node(package="race_vehicle_interface",executable="vehicle_interface_node",
        name="vehicle_interface_node",output="screen",parameters=[
            os.path.join(vehicle_share,"config","vehicle_interface.yaml"),
            {"allow_actuation":True,"steering_only":False,"maximum_abs_stage":1}])
    return LaunchDescription([
        LogInfo(msg=(
            "LOW-SPEED PATH FOLLOWING: Pure Pursuit target "
            f"{LOW_SPEED_STAGE_1_MPS:.6f} m/s; forward command is hard-limited "
            "to stage 1; both command gates start disarmed"
        )),
        autonomy,bridge,interface])
