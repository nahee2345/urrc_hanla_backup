"""Stable semantic output contracts for the perception node."""

from types import MappingProxyType

SEMANTIC_MASK_TOPICS = MappingProxyType({
    "road": "/perception/masks/road", "white_line": "/perception/masks/white_line",
    "yellow_line": "/perception/masks/yellow_line", "red_light": "/perception/masks/red_light",
    "yellow_light": "/perception/masks/yellow_light", "green_light": "/perception/masks/green_light",
    "left_sign": "/perception/masks/left_light", "other_light": "/perception/masks/other_light",
    "stop_line": "/perception/masks/stop_line", "speed_20_sign": "/perception/masks/traffic20",
    "c_line": "/perception/masks/c_line", "words": "/perception/masks/words",
})
COMPATIBILITY_MASK_TOPICS = MappingProxyType({
    "road": "/camera/road_mask", "white_line": "/camera/white_line_mask",
    "yellow_line": "/camera/yellow_line_mask",
})
