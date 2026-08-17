#!/usr/bin/env python3
"""Collect a 30-second inference diagnostic interval without image subscription."""

import json
import statistics
import time

import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class Probe(Node):
    def __init__(self):
        super().__init__("stage2_inference_probe")
        self.fps = []
        self.performance = []
        self.create_subscription(String, "/camera/realtime_fps", self._fps, 10)
        self.create_subscription(
            String, "/camera/performance_diagnostics", self._performance, 10
        )

    def _fps(self, message):
        self.fps.append(json.loads(message.data))

    def _performance(self, message):
        self.performance.append(json.loads(message.data))


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


def buffer_delta(messages):
    first = messages[0]["latest_buffer"]
    last = messages[-1]["latest_buffer"]
    return {key: int(last[key]) - int(first[key]) for key in last}


def main():
    rclpy.init()
    node = Probe()
    # Wait for the first complete pair so the counter delta covers the test interval.
    deadline = time.monotonic() + 10.0
    while rclpy.ok() and (not node.fps or not node.performance):
        if time.monotonic() >= deadline:
            raise RuntimeError("diagnostic topics did not arrive")
        rclpy.spin_once(node, timeout_sec=0.1)
    node.fps.clear()
    node.performance.clear()
    started = time.monotonic()
    while rclpy.ok() and time.monotonic() - started < 30.0:
        rclpy.spin_once(node, timeout_sec=0.05)
    if len(node.fps) < 2 or len(node.performance) < 2:
        raise RuntimeError("insufficient diagnostic samples")
    latest_performance = node.performance[-1]
    output = {
        "duration_s": time.monotonic() - started,
        "diagnostic_samples": len(node.fps),
        "camera_callback": rate_summary(node.fps, "image_callback"),
        "inference": rate_summary(node.fps, "inference_unique_fps"),
        "semantic": rate_summary(node.fps, "semantic_unique_fps"),
        "buffer_delta": buffer_delta(node.fps),
        "callback_store_ms": node.fps[-1]["callback_store_ms"],
        "latency_ms": latest_performance["statistics"],
        "qos": latest_performance["input_qos"],
        "executor": latest_performance["executor"],
    }
    print(json.dumps(output, indent=2))
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
