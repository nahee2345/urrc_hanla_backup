#!/usr/bin/env python3
"""One-shot Stage 2 probe for raw image and RealSense metadata delivery rates."""

import json
import statistics
import time

import rclpy
from rclpy.node import Node
from rclpy.qos import HistoryPolicy, QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import Image
from realsense2_camera_msgs.msg import Metadata


class Probe(Node):
    def __init__(self):
        super().__init__("stage2_rate_probe")
        image_qos = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=5,
            reliability=ReliabilityPolicy.BEST_EFFORT,
        )
        metadata_qos = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=5,
            reliability=ReliabilityPolicy.RELIABLE,
        )
        self.samples = {"raw": [], "metadata": []}
        self.create_subscription(Image, "/camera/image_raw", self._raw, image_qos)
        self.create_subscription(
            Metadata, "/camera/camera/color/metadata", self._metadata, metadata_qos
        )

    @staticmethod
    def _stamp_seconds(stamp):
        return float(stamp.sec) + float(stamp.nanosec) * 1e-9

    def _raw(self, message):
        self.samples["raw"].append((self._stamp_seconds(message.header.stamp), time.monotonic()))

    def _metadata(self, message):
        self.samples["metadata"].append(
            (self._stamp_seconds(message.header.stamp), time.monotonic())
        )


def summarize(samples):
    if len(samples) < 2:
        return {"samples": len(samples), "header_fps": 0.0, "arrival_fps": 0.0}
    headers = [sample[0] for sample in samples]
    arrivals = [sample[1] for sample in samples]
    gaps_ms = [(b - a) * 1000.0 for a, b in zip(headers, headers[1:])]
    ordered = sorted(gaps_ms)

    def percentile(fraction):
        index = round((len(ordered) - 1) * fraction)
        return ordered[index]

    return {
        "samples": len(samples),
        "header_fps": (len(samples) - 1) / (headers[-1] - headers[0]),
        "arrival_fps": (len(samples) - 1) / (arrivals[-1] - arrivals[0]),
        "gap_ms": {
            "p50": statistics.median(gaps_ms),
            "p95": percentile(0.95),
            "p99": percentile(0.99),
            "max": max(gaps_ms),
        },
    }


def main():
    rclpy.init()
    node = Probe()
    started = time.monotonic()
    while rclpy.ok() and time.monotonic() - started < 30.0:
        rclpy.spin_once(node, timeout_sec=0.05)
    print(json.dumps({name: summarize(values) for name, values in node.samples.items()}, indent=2))
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
