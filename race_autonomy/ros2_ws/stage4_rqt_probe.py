#!/usr/bin/env python3
"""Measure the 30-second two-view RQT production performance interval."""

import json
import statistics
import subprocess
import time

import psutil
import rclpy
from rclpy.node import Node
from rclpy.qos import HistoryPolicy, QoSProfile, ReliabilityPolicy
from realsense2_camera_msgs.msg import Metadata
from std_msgs.msg import String


PROCESS_NAMES = (
    "realsense2_camera_node",
    "camera_yolo_inference_node",
    "camera_image_path_node",
    "rqt_image_view",
)


class Probe(Node):
    def __init__(self):
        super().__init__("stage4_rqt_probe")
        self.upstream = []
        self.path = []
        self.metadata = []
        self.create_subscription(String, "/camera/realtime_fps", self._upstream, 10)
        self.create_subscription(String, "/camera/path_realtime_fps", self._path, 10)
        metadata_qos = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=5,
            reliability=ReliabilityPolicy.RELIABLE,
        )
        self.create_subscription(
            Metadata, "/camera/camera/color/metadata", self._metadata, metadata_qos
        )

    def _upstream(self, message):
        self.upstream.append(json.loads(message.data))

    def _path(self, message):
        self.path.append(json.loads(message.data))

    def _metadata(self, message):
        stamp = message.header.stamp
        self.metadata.append(
            (float(stamp.sec) + float(stamp.nanosec) * 1e-9, time.monotonic())
        )


def rate_summary(messages, field):
    result = {}
    for window in ("1s", "5s", "10s"):
        values = [float(message[field][window]["header_fps"]) for message in messages]
        result[window] = {
            "min": min(values),
            "median": statistics.median(values),
            "max": max(values),
        }
    return result


def throughput_summary(messages, field):
    result = {}
    for window_seconds in (1, 5, 10):
        window = f"{window_seconds}s"
        values = [
            float(message[field][window]["unique_frames"]) / window_seconds
            for message in messages
        ]
        result[window] = {
            "min": min(values),
            "median": statistics.median(values),
            "max": max(values),
        }
    return result


def counter_delta(messages, fields):
    first, last = messages[0], messages[-1]
    return {field: int(last[field]) - int(first[field]) for field in fields}


def metadata_summary(samples):
    headers = [sample[0] for sample in samples]
    arrivals = [sample[1] for sample in samples]
    return {
        "samples": len(samples),
        "header_fps": (len(samples) - 1) / (headers[-1] - headers[0]),
        "arrival_fps": (len(samples) - 1) / (arrivals[-1] - arrivals[0]),
    }


def distribution(values):
    ordered = sorted(float(value) for value in values)
    return {
        "samples": len(ordered),
        "median": statistics.median(ordered),
        "p95": ordered[round((len(ordered) - 1) * 0.95)],
        "max": max(ordered),
    }


def target_processes():
    found = []
    for process in psutil.process_iter(("pid", "cmdline")):
        try:
            command = " ".join(process.info["cmdline"] or ())
            if any(name in command for name in PROCESS_NAMES):
                process.cpu_percent(None)
                found.append(process)
        except (psutil.AccessDenied, psutil.NoSuchProcess):
            continue
    return found


def gpu_sample():
    result = subprocess.run(
        ["nvidia-smi", "--query-gpu=utilization.gpu,memory.used",
         "--format=csv,noheader,nounits"],
        check=True, capture_output=True, text=True,
    )
    utilization, memory = result.stdout.splitlines()[0].split(",")
    return float(utilization.strip()), float(memory.strip())


def main():
    rclpy.init()
    node = Probe()
    deadline = time.monotonic() + 15.0
    while rclpy.ok() and (not node.upstream or not node.path):
        if time.monotonic() >= deadline:
            raise RuntimeError("upstream/path diagnostics did not arrive")
        rclpy.spin_once(node, timeout_sec=0.1)
    processes = target_processes()
    psutil.cpu_percent(None)
    node.upstream.clear()
    node.path.clear()
    node.metadata.clear()
    cpu_system = []
    cpu_processes = []
    ram_system = []
    ram_processes = []
    gpu_utilization = []
    gpu_memory = []
    started = time.monotonic()
    next_resource_sample = started + 1.0
    while rclpy.ok() and time.monotonic() - started < 30.0:
        rclpy.spin_once(node, timeout_sec=0.05)
        now = time.monotonic()
        if now < next_resource_sample:
            continue
        next_resource_sample += 1.0
        cpu_system.append(psutil.cpu_percent(None))
        cpu_processes.append(sum(
            process.cpu_percent(None) for process in processes if process.is_running()
        ))
        ram_system.append(psutil.virtual_memory().percent)
        ram_processes.append(sum(
            process.memory_info().rss for process in processes if process.is_running()
        ) / (1024.0 * 1024.0))
        gpu_util, gpu_mem = gpu_sample()
        gpu_utilization.append(gpu_util)
        gpu_memory.append(gpu_mem)
    if len(node.upstream) < 2 or len(node.path) < 2 or len(node.metadata) < 2:
        raise RuntimeError("insufficient Stage 4 samples")
    output = {
        "duration_s": time.monotonic() - started,
        "process_count": len(processes),
        "metadata": metadata_summary(node.metadata),
        "camera_callback": rate_summary(node.upstream, "image_callback"),
        "inference": rate_summary(node.upstream, "inference_unique_fps"),
        "semantic": rate_summary(node.upstream, "semantic_unique_fps"),
        "path": rate_summary(node.path, "path_published"),
        "perception_overlay": rate_summary(node.upstream, "perception_overlay_fps"),
        "path_overlay": rate_summary(node.path, "path_overlay_fps"),
        "perception_overlay_throughput": throughput_summary(
            node.upstream, "perception_overlay_fps"),
        "path_overlay_throughput": throughput_summary(
            node.path, "path_overlay_fps"),
        "path_counter_delta": counter_delta(
            node.path,
            ("received_count", "accepted_count", "processed_count",
             "published_count", "duplicate", "stale"),
        ),
        "backlog": {
            "min": min(int(message["backlog"]) for message in node.path),
            "max": max(int(message["backlog"]) for message in node.path),
            "final": int(node.path[-1]["backlog"]),
        },
        "resources": {
            "system_cpu_percent": distribution(cpu_system),
            "production_rqt_cpu_percent": distribution(cpu_processes),
            "system_ram_percent": distribution(ram_system),
            "production_rqt_rss_mib": distribution(ram_processes),
            "gpu_utilization_percent": distribution(gpu_utilization),
            "gpu_memory_mib": distribution(gpu_memory),
        },
    }
    print(json.dumps(output, indent=2))
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
