std_msgs/Header header
uint16 image_width
uint16 image_height

# Alternating flattened start,end-exclusive pairs for non-zero binary runs.
uint32[] road_rle
uint32[] lane_rle
uint32[] words_rle
uint32[] stop_line_rle
uint32[] c_line_rle

uint32 uncompressed_bytes
uint32 encoded_bytes
