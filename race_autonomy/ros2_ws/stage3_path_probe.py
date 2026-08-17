#!/usr/bin/env python3
"""Measure Stage 3 camera, inference, semantic, and path rates for 30 seconds."""

import json
import statistics
import time

import rclpy
from rclpy.node import Node
from rclpy.qos import HistoryPolicy, QoSProfile, ReliabilityPolicy
from realsense2_camera_msgs.msg import Metadata
from std_msgs.msg import String


class Probe(Node):
    def __init__(self):
        super().__init__("stage3_path_probe")
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


def main():
    rclpy.init()
    node = Probe()
    deadline = time.monotonic() + 15.0
    while rclpy.ok() and (not node.upstream or not node.path):
        if time.monotonic() >= deadline:
            raise RuntimeError("upstream/path diagnostics did not arrive")
        rclpy.spin_once(node, timeout_sec=0.1)
    node.upstream.clear()
    node.path.clear()
    node.metadata.clear()
    started = time.monotonic()
    while rclpy.ok() and time.monotonic() - started < 30.0:
        rclpy.spin_once(node, timeout_sec=0.05)
    if len(node.upstream) < 2 or len(node.path) < 2 or len(node.metadata) < 2:
        raise RuntimeError("insufficient Stage 3 samples")
    output = {
        "duration_s": time.monotonic() - started,
        "metadata": metadata_summary(node.metadata),
        "camera_callback": rate_summary(node.upstream, "image_callback"),
        "inference": rate_summary(node.upstream, "inference_unique_fps"),
        "semantic": rate_summary(node.upstream, "semantic_unique_fps"),
        "path_semantic_received": rate_summary(node.path, "semantic_received"),
        "path_processed": rate_summary(node.path, "path_processed"),
        "path_published": rate_summary(node.path, "path_published"),
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
        "path_processing_ms": node.path[-1]["path_processing_ms"],
    }
    print(json.dumps(output, indent=2))
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
