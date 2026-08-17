"""Launch the official RGB YOLO-Seg node; depth helpers are opt-in."""
from pathlib import Path
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

ARGUMENTS = (
    ("backend", "tensorrt"), ("segmentation_model_path", ""), ("class_manifest_path", ""),
    ("device", "cuda:0"), ("require_cuda", "true"), ("input_size", "640"),
    ("confidence_threshold", "0.25"), ("mask_threshold", "0.5"),
    ("max_image_age_sec", "0.4"), ("max_inference_latency_ms", "300.0"),
    ("input_image_topic", "/camera/image_raw"), ("input_reliability", "best_effort"),
    ("input_camera_info_topic", "/camera/camera_info"),
    ("expected_image_width", "640"), ("expected_image_height", "480"),
    ("publish_diagnostics", "true"), ("publish_debug_image", "true"),
    ("warmup_count", "5"),
    ("use_sim_time", "false"), ("enable_depth_assist", "false"),
)


def generate_launch_description():
    share = Path(get_package_share_directory("camera_yolo_inference"))
    config = str(share / "config" / "yolo_inference.yaml")
    manifest = str(share / "config" / "class_manifest.yaml")
    model = str(share / "models" / "hanla_yolo11n_seg_best.engine")
    declarations = [DeclareLaunchArgument(
        name, default_value=(manifest if name == "class_manifest_path" else
                             model if name == "segmentation_model_path" else default))
        for name, default in ARGUMENTS]
    params = {name: LaunchConfiguration(name) for name, _ in ARGUMENTS
              if name != "enable_depth_assist"}
    depth_condition = IfCondition(LaunchConfiguration("enable_depth_assist"))
    return LaunchDescription(declarations + [
        Node(package="camera_yolo_inference", executable="camera_yolo_inference_node",
             parameters=[config, params], output="screen"),
        Node(package="camera_yolo_inference", executable="stop_line_depth_node",
             condition=depth_condition, output="screen"),
        Node(package="camera_yolo_inference", executable="yellow_line_depth_node",
             condition=depth_condition, output="screen"),
    ])
