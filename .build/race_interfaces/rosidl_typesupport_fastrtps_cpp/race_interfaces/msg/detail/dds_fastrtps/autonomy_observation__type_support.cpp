// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from race_interfaces:msg/AutonomyObservation.idl
// generated code does not contain a copyright notice
#include "race_interfaces/msg/detail/autonomy_observation__rosidl_typesupport_fastrtps_cpp.hpp"
#include "race_interfaces/msg/detail/autonomy_observation__functions.h"
#include "race_interfaces/msg/detail/autonomy_observation__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
bool cdr_serialize_key(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
size_t get_serialized_size_key(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_key_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace race_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
cdr_serialize(
  const race_interfaces::msg::AutonomyObservation & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);

  // Member: perception_valid
  cdr << (ros_message.perception_valid ? true : false);

  // Member: imu_valid
  cdr << (ros_message.imu_valid ? true : false);

  // Member: speed_valid
  cdr << (ros_message.speed_valid ? true : false);

  // Member: stop_detected
  cdr << (ros_message.stop_detected ? true : false);

  // Member: traffic_light
  cdr << ros_message.traffic_light;

  // Member: pitch_deg
  cdr << ros_message.pitch_deg;

  // Member: roll_deg
  cdr << ros_message.roll_deg;

  // Member: yaw_deg
  cdr << ros_message.yaw_deg;

  // Member: speed_kph
  cdr << ros_message.speed_kph;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  race_interfaces::msg::AutonomyObservation & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: perception_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.perception_valid = tmp ? true : false;
  }

  // Member: imu_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.imu_valid = tmp ? true : false;
  }

  // Member: speed_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.speed_valid = tmp ? true : false;
  }

  // Member: stop_detected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.stop_detected = tmp ? true : false;
  }

  // Member: traffic_light
  cdr >> ros_message.traffic_light;

  // Member: pitch_deg
  cdr >> ros_message.pitch_deg;

  // Member: roll_deg
  cdr >> ros_message.roll_deg;

  // Member: yaw_deg
  cdr >> ros_message.yaw_deg;

  // Member: speed_kph
  cdr >> ros_message.speed_kph;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
get_serialized_size(
  const race_interfaces::msg::AutonomyObservation & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header
  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);

  // Member: perception_valid
  {
    size_t item_size = sizeof(ros_message.perception_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: imu_valid
  {
    size_t item_size = sizeof(ros_message.imu_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: speed_valid
  {
    size_t item_size = sizeof(ros_message.speed_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: stop_detected
  {
    size_t item_size = sizeof(ros_message.stop_detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: traffic_light
  {
    size_t item_size = sizeof(ros_message.traffic_light);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: pitch_deg
  {
    size_t item_size = sizeof(ros_message.pitch_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: roll_deg
  {
    size_t item_size = sizeof(ros_message.roll_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: yaw_deg
  {
    size_t item_size = sizeof(ros_message.yaw_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: speed_kph
  {
    size_t item_size = sizeof(ros_message.speed_kph);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
max_serialized_size_AutonomyObservation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: perception_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: imu_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: speed_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: stop_detected
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: traffic_light
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: pitch_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: roll_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: yaw_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: speed_kph
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = race_interfaces::msg::AutonomyObservation;
    is_plain =
      (
      offsetof(DataType, speed_kph) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
cdr_serialize_key(
  const race_interfaces::msg::AutonomyObservation & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.header,
    cdr);

  // Member: perception_valid
  cdr << (ros_message.perception_valid ? true : false);

  // Member: imu_valid
  cdr << (ros_message.imu_valid ? true : false);

  // Member: speed_valid
  cdr << (ros_message.speed_valid ? true : false);

  // Member: stop_detected
  cdr << (ros_message.stop_detected ? true : false);

  // Member: traffic_light
  cdr << ros_message.traffic_light;

  // Member: pitch_deg
  cdr << ros_message.pitch_deg;

  // Member: roll_deg
  cdr << ros_message.roll_deg;

  // Member: yaw_deg
  cdr << ros_message.yaw_deg;

  // Member: speed_kph
  cdr << ros_message.speed_kph;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
get_serialized_size_key(
  const race_interfaces::msg::AutonomyObservation & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header
  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.header, current_alignment);

  // Member: perception_valid
  {
    size_t item_size = sizeof(ros_message.perception_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: imu_valid
  {
    size_t item_size = sizeof(ros_message.imu_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: speed_valid
  {
    size_t item_size = sizeof(ros_message.speed_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: stop_detected
  {
    size_t item_size = sizeof(ros_message.stop_detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: traffic_light
  {
    size_t item_size = sizeof(ros_message.traffic_light);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: pitch_deg
  {
    size_t item_size = sizeof(ros_message.pitch_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: roll_deg
  {
    size_t item_size = sizeof(ros_message.roll_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: yaw_deg
  {
    size_t item_size = sizeof(ros_message.yaw_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: speed_kph
  {
    size_t item_size = sizeof(ros_message.speed_kph);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
max_serialized_size_key_AutonomyObservation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: perception_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: imu_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: speed_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: stop_detected
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: traffic_light
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: pitch_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: roll_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: yaw_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: speed_kph
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = race_interfaces::msg::AutonomyObservation;
    is_plain =
      (
      offsetof(DataType, speed_kph) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _AutonomyObservation__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const race_interfaces::msg::AutonomyObservation *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _AutonomyObservation__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<race_interfaces::msg::AutonomyObservation *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _AutonomyObservation__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const race_interfaces::msg::AutonomyObservation *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _AutonomyObservation__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_AutonomyObservation(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _AutonomyObservation__callbacks = {
  "race_interfaces::msg",
  "AutonomyObservation",
  _AutonomyObservation__cdr_serialize,
  _AutonomyObservation__cdr_deserialize,
  _AutonomyObservation__get_serialized_size,
  _AutonomyObservation__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _AutonomyObservation__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_AutonomyObservation__callbacks,
  get_message_typesupport_handle_function,
  &race_interfaces__msg__AutonomyObservation__get_type_hash,
  &race_interfaces__msg__AutonomyObservation__get_type_description,
  &race_interfaces__msg__AutonomyObservation__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace race_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_race_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<race_interfaces::msg::AutonomyObservation>()
{
  return &race_interfaces::msg::typesupport_fastrtps_cpp::_AutonomyObservation__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, race_interfaces, msg, AutonomyObservation)() {
  return &race_interfaces::msg::typesupport_fastrtps_cpp::_AutonomyObservation__handle;
}

#ifdef __cplusplus
}
#endif
