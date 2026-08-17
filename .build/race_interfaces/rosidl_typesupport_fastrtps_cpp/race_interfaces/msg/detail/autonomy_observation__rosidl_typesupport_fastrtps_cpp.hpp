// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from race_interfaces:msg/AutonomyObservation.idl
// generated code does not contain a copyright notice

#ifndef RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "race_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "race_interfaces/msg/detail/autonomy_observation__struct.hpp"

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

#include "fastcdr/Cdr.h"

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
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  race_interfaces::msg::AutonomyObservation & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
get_serialized_size(
  const race_interfaces::msg::AutonomyObservation & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
max_serialized_size_AutonomyObservation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
cdr_serialize_key(
  const race_interfaces::msg::AutonomyObservation & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
get_serialized_size_key(
  const race_interfaces::msg::AutonomyObservation & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
max_serialized_size_key_AutonomyObservation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace race_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_race_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, race_interfaces, msg, AutonomyObservation)();

#ifdef __cplusplus
}
#endif

#endif  // RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
