// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from race_interfaces:msg/AutonomyObservation.idl
// generated code does not contain a copyright notice
#include "race_interfaces/msg/detail/autonomy_observation__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "race_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "race_interfaces/msg/detail/autonomy_observation__struct.h"
#include "race_interfaces/msg/detail/autonomy_observation__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_race_interfaces
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_race_interfaces
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_race_interfaces
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_race_interfaces
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_race_interfaces
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_race_interfaces
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_race_interfaces
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_race_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _AutonomyObservation__ros_msg_type = race_interfaces__msg__AutonomyObservation;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
bool cdr_serialize_race_interfaces__msg__AutonomyObservation(
  const race_interfaces__msg__AutonomyObservation * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: perception_valid
  {
    cdr << (ros_message->perception_valid ? true : false);
  }

  // Field name: imu_valid
  {
    cdr << (ros_message->imu_valid ? true : false);
  }

  // Field name: speed_valid
  {
    cdr << (ros_message->speed_valid ? true : false);
  }

  // Field name: stop_detected
  {
    cdr << (ros_message->stop_detected ? true : false);
  }

  // Field name: traffic_light
  {
    cdr << ros_message->traffic_light;
  }

  // Field name: pitch_deg
  {
    cdr << ros_message->pitch_deg;
  }

  // Field name: roll_deg
  {
    cdr << ros_message->roll_deg;
  }

  // Field name: yaw_deg
  {
    cdr << ros_message->yaw_deg;
  }

  // Field name: speed_kph
  {
    cdr << ros_message->speed_kph;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
bool cdr_deserialize_race_interfaces__msg__AutonomyObservation(
  eprosima::fastcdr::Cdr & cdr,
  race_interfaces__msg__AutonomyObservation * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: perception_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->perception_valid = tmp ? true : false;
  }

  // Field name: imu_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->imu_valid = tmp ? true : false;
  }

  // Field name: speed_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->speed_valid = tmp ? true : false;
  }

  // Field name: stop_detected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->stop_detected = tmp ? true : false;
  }

  // Field name: traffic_light
  {
    cdr >> ros_message->traffic_light;
  }

  // Field name: pitch_deg
  {
    cdr >> ros_message->pitch_deg;
  }

  // Field name: roll_deg
  {
    cdr >> ros_message->roll_deg;
  }

  // Field name: yaw_deg
  {
    cdr >> ros_message->yaw_deg;
  }

  // Field name: speed_kph
  {
    cdr >> ros_message->speed_kph;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
size_t get_serialized_size_race_interfaces__msg__AutonomyObservation(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AutonomyObservation__ros_msg_type * ros_message = static_cast<const _AutonomyObservation__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: perception_valid
  {
    size_t item_size = sizeof(ros_message->perception_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: imu_valid
  {
    size_t item_size = sizeof(ros_message->imu_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_valid
  {
    size_t item_size = sizeof(ros_message->speed_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: stop_detected
  {
    size_t item_size = sizeof(ros_message->stop_detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: traffic_light
  {
    size_t item_size = sizeof(ros_message->traffic_light);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pitch_deg
  {
    size_t item_size = sizeof(ros_message->pitch_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: roll_deg
  {
    size_t item_size = sizeof(ros_message->roll_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yaw_deg
  {
    size_t item_size = sizeof(ros_message->yaw_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_kph
  {
    size_t item_size = sizeof(ros_message->speed_kph);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
size_t max_serialized_size_race_interfaces__msg__AutonomyObservation(
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

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: perception_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: imu_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: speed_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: stop_detected
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: traffic_light
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: pitch_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: roll_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: yaw_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: speed_kph
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
    using DataType = race_interfaces__msg__AutonomyObservation;
    is_plain =
      (
      offsetof(DataType, speed_kph) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
bool cdr_serialize_key_race_interfaces__msg__AutonomyObservation(
  const race_interfaces__msg__AutonomyObservation * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: perception_valid
  {
    cdr << (ros_message->perception_valid ? true : false);
  }

  // Field name: imu_valid
  {
    cdr << (ros_message->imu_valid ? true : false);
  }

  // Field name: speed_valid
  {
    cdr << (ros_message->speed_valid ? true : false);
  }

  // Field name: stop_detected
  {
    cdr << (ros_message->stop_detected ? true : false);
  }

  // Field name: traffic_light
  {
    cdr << ros_message->traffic_light;
  }

  // Field name: pitch_deg
  {
    cdr << ros_message->pitch_deg;
  }

  // Field name: roll_deg
  {
    cdr << ros_message->roll_deg;
  }

  // Field name: yaw_deg
  {
    cdr << ros_message->yaw_deg;
  }

  // Field name: speed_kph
  {
    cdr << ros_message->speed_kph;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
size_t get_serialized_size_key_race_interfaces__msg__AutonomyObservation(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AutonomyObservation__ros_msg_type * ros_message = static_cast<const _AutonomyObservation__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: perception_valid
  {
    size_t item_size = sizeof(ros_message->perception_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: imu_valid
  {
    size_t item_size = sizeof(ros_message->imu_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_valid
  {
    size_t item_size = sizeof(ros_message->speed_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: stop_detected
  {
    size_t item_size = sizeof(ros_message->stop_detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: traffic_light
  {
    size_t item_size = sizeof(ros_message->traffic_light);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pitch_deg
  {
    size_t item_size = sizeof(ros_message->pitch_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: roll_deg
  {
    size_t item_size = sizeof(ros_message->roll_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yaw_deg
  {
    size_t item_size = sizeof(ros_message->yaw_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_kph
  {
    size_t item_size = sizeof(ros_message->speed_kph);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
size_t max_serialized_size_key_race_interfaces__msg__AutonomyObservation(
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
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: perception_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: imu_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: speed_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: stop_detected
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: traffic_light
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: pitch_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: roll_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: yaw_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: speed_kph
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
    using DataType = race_interfaces__msg__AutonomyObservation;
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
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const race_interfaces__msg__AutonomyObservation * ros_message = static_cast<const race_interfaces__msg__AutonomyObservation *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_race_interfaces__msg__AutonomyObservation(ros_message, cdr);
}

static bool _AutonomyObservation__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  race_interfaces__msg__AutonomyObservation * ros_message = static_cast<race_interfaces__msg__AutonomyObservation *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_race_interfaces__msg__AutonomyObservation(cdr, ros_message);
}

static uint32_t _AutonomyObservation__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_race_interfaces__msg__AutonomyObservation(
      untyped_ros_message, 0));
}

static size_t _AutonomyObservation__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_race_interfaces__msg__AutonomyObservation(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AutonomyObservation = {
  "race_interfaces::msg",
  "AutonomyObservation",
  _AutonomyObservation__cdr_serialize,
  _AutonomyObservation__cdr_deserialize,
  _AutonomyObservation__get_serialized_size,
  _AutonomyObservation__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _AutonomyObservation__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AutonomyObservation,
  get_message_typesupport_handle_function,
  &race_interfaces__msg__AutonomyObservation__get_type_hash,
  &race_interfaces__msg__AutonomyObservation__get_type_description,
  &race_interfaces__msg__AutonomyObservation__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, race_interfaces, msg, AutonomyObservation)() {
  return &_AutonomyObservation__type_support;
}

#if defined(__cplusplus)
}
#endif
