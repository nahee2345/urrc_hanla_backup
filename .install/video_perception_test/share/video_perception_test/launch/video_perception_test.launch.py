"""Saved-video publisher + production CUDA inference + optional RQT."""

from pathlib import Path
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    test_share = Path(get_package_share_directory("video_perception_test"))
    source_root = next(
        candidate for candidate in Path(__file__).resolve().parents
        if (candidate / "input" / "test_video.mp4").is_file())
    yolo_share = Path(get_package_share_directory("camera_yolo_inference"))
    config = str(test_share / "config" / "video_perception_test.yaml")
    arguments = {
        "video_path": str(source_root / "input" / "test_video.mp4"),
        "playback_rate": "1.0", "loop": "false", "start_frame": "0",
        "startup_delay_sec": "0.0",
        "frame_id": "camera_color_optical_frame", "publish_original_debug": "true",
        "save_annotated_video": "false", "launch_rqt": "false",
        "enable_recorder": "false",
        "image_reliability": "reliable",
        "original_debug_stride": "2",
        "output_directory": str(source_root / "output"),
        "metadata_filename": "perception_results.jsonl",
        "summary_filename": "performance_summary.json",
        "annotated_video_filename": "annotated_result.mp4",
        "expected_image_width": "640", "expected_image_height": "480",
    }
    declarations = [DeclareLaunchArgument(name, default_value=value)
                    for name, value in arguments.items()]
    publisher = Node(
        package="video_perception_test", executable="video_image_publisher",
        parameters=[config, {
            "video_path": LaunchConfiguration("video_path"),
            "playback_rate": LaunchConfiguration("playback_rate"),
            "loop": LaunchConfiguration("loop"),
            "start_frame": LaunchConfiguration("start_frame"),
            "startup_delay_sec": LaunchConfiguration("startup_delay_sec"),
            "frame_id": LaunchConfiguration("frame_id"),
            "publish_original_debug": LaunchConfiguration("publish_original_debug"),
            "output_reliability": LaunchConfiguration("image_reliability"),
            "original_debug_stride": LaunchConfiguration("original_debug_stride"),
            "publish_fps": 30.0, "output_width": 640, "output_height": 480,
        }], output="screen")
    inference = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(str(yolo_share / "launch" / "yolo_inference.launch.py")),
        launch_arguments={
            "device": "cuda:0", "require_cuda": "true",
            "input_image_topic": "/camera/image_raw",
            "input_reliability": LaunchConfiguration("image_reliability"),
            "input_camera_info_topic": "/camera/camera_info",
            "expected_image_width": LaunchConfiguration("expected_image_width"),
            "expected_image_height": LaunchConfiguration("expected_image_height"),
            "enable_depth_assist": "false",
        }.items())
    recorder = Node(
        package="video_perception_test", executable="result_recorder",
        parameters=[config, {
            "output_directory": LaunchConfiguration("output_directory"),
            "metadata_filename": LaunchConfiguration("metadata_filename"),
            "summary_filename": LaunchConfiguration("summary_filename"),
            "annotated_video_filename": LaunchConfiguration("annotated_video_filename"),
            "save_annotated_video": LaunchConfiguration("save_annotated_video"),
        }], condition=IfCondition(LaunchConfiguration("enable_recorder")), output="screen")
    original_rqt = Node(
        package="rqt_image_view", executable="rqt_image_view", name="video_original_rqt",
        arguments=["/video_test/original_image"],
        condition=IfCondition(LaunchConfiguration("launch_rqt")), output="screen")
    annotated_rqt = Node(
        package="rqt_image_view", executable="rqt_image_view", name="video_annotated_rqt",
        arguments=["/perception/detections_image"],
        condition=IfCondition(LaunchConfiguration("launch_rqt")), output="screen")
    return LaunchDescription(declarations + [publisher, inference, recorder,
                                              original_rqt, annotated_rqt])
