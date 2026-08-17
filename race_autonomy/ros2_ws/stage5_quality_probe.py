#!/usr/bin/env python3
"""Capture canonical Stage 5 overlays and summarize live perception/path output."""

import json
from collections import Counter, defaultdict
from pathlib import Path
import statistics
import time

import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import HistoryPolicy, QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import Image
from std_msgs.msg import String


OUTPUT = Path("/tmp/stage5_frames")


class Probe(Node):
    def __init__(self):
        super().__init__("stage5_quality_probe")
        image_qos = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=1,
            reliability=ReliabilityPolicy.BEST_EFFORT,
        )
        self.latest = {}
        self.detection_frames = 0
        self.class_frames = Counter()
        self.class_instances = Counter()
        self.class_confidences = defaultdict(list)
        self.path_states = Counter()
        self.path_confidences = []
        self.lateral_shifts = []
        self.path_valid_frames = 0
        self.event_captures = Counter()
        self.create_subscription(
            Image, "/camera/perception_overlay_image", self._perception, image_qos)
        self.create_subscription(
            Image, "/camera/path_overlay_image", self._path, image_qos)
        self.create_subscription(
            String, "/perception/detections_json", self._detections, 10)
        self.create_subscription(String, "/camera/path_metrics", self._metrics, 10)

    def _perception(self, message):
        self.latest["perception"] = message

    def _path(self, message):
        self.latest["path"] = message

    def _detections(self, message):
        document = json.loads(message.data)
        self.detection_frames += 1
        present = set()
        for detection in document.get("detections", ()):
            name = str(detection["class_name"])
            present.add(name)
            self.class_instances[name] += 1
            self.class_confidences[name].append(float(detection["confidence"]))
        self.class_frames.update(present)
        for name in present & {"W_line", "Y_line", "stop", "words", "C_line"}:
            if self.event_captures[name] >= 2 or len(self.latest) < 2:
                continue
            self.event_captures[name] += 1
            index = self.event_captures[name]
            for view, image in self.latest.items():
                save_image(image, OUTPUT / f"event_{name}_{index}_{view}.png")

    def _metrics(self, message):
        document = json.loads(message.data)
        self.path_states[str(document.get("path_state", "UNKNOWN"))] += 1
        self.path_confidences.append(float(document.get("path_confidence", 0.0)))
        if document.get("path_valid"):
            self.path_valid_frames += 1
        shift = document.get("lateral_shift_px")
        if shift is not None:
            self.lateral_shifts.append(abs(float(shift)))


def save_image(message, path):
    raw = np.frombuffer(message.data, dtype=np.uint8)
    image = raw.reshape(message.height, message.step)[:, :message.width * 3]
    image = image.reshape(message.height, message.width, 3)
    if message.encoding.lower() == "rgb8":
        image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
    cv2.imwrite(str(path), image)


def percentile(values, fraction):
    ordered = sorted(values)
    return ordered[round((len(ordered) - 1) * fraction)] if ordered else 0.0


def main():
    OUTPUT.mkdir(parents=True, exist_ok=True)
    rclpy.init()
    node = Probe()
    started = time.monotonic()
    next_capture = started + 2.0
    capture_index = 0
    while rclpy.ok() and time.monotonic() - started < 14.0:
        rclpy.spin_once(node, timeout_sec=0.05)
        now = time.monotonic()
        if now < next_capture or len(node.latest) < 2:
            continue
        next_capture += 2.0
        capture_index += 1
        for name, message in node.latest.items():
            save_image(message, OUTPUT / f"{name}_{capture_index:02d}.png")
    classes = {}
    for name, count in sorted(node.class_instances.items()):
        confidences = node.class_confidences[name]
        classes[name] = {
            "frames_present": node.class_frames[name],
            "instances": count,
            "confidence_median": statistics.median(confidences),
            "confidence_max": max(confidences),
        }
    output = {
        "duration_s": time.monotonic() - started,
        "capture_pairs": capture_index,
        "detection_frames": node.detection_frames,
        "classes": classes,
        "path_states": dict(node.path_states),
        "path_valid_frames": node.path_valid_frames,
        "path_confidence_median": (
            statistics.median(node.path_confidences) if node.path_confidences else 0.0),
        "absolute_lateral_shift_px": {
            "p50": percentile(node.lateral_shifts, 0.50),
            "p95": percentile(node.lateral_shifts, 0.95),
            "max": max(node.lateral_shifts, default=0.0),
        },
        "event_captures": dict(node.event_captures),
        "output_directory": str(OUTPUT),
    }
    print(json.dumps(output, indent=2))
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
