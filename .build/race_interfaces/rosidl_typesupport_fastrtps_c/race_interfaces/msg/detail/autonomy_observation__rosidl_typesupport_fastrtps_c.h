// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from race_interfaces:msg/AutonomyObservation.idl
// generated code does not contain a copyright notice
#ifndef RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "race_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "race_interfaces/msg/detail/autonomy_observation__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
bool cdr_serialize_race_interfaces__msg__AutonomyObservation(
  const race_interfaces__msg__AutonomyObservation * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
bool cdr_deserialize_race_interfaces__msg__AutonomyObservation(
  eprosima::fastcdr::Cdr &,
  race_interfaces__msg__AutonomyObservation * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
size_t get_serialized_size_race_interfaces__msg__AutonomyObservation(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
size_t max_serialized_size_race_interfaces__msg__AutonomyObservation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
bool cdr_serialize_key_race_interfaces__msg__AutonomyObservation(
  const race_interfaces__msg__AutonomyObservation * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
size_t get_serialized_size_key_race_interfaces__msg__AutonomyObservation(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
size_t max_serialized_size_key_race_interfaces__msg__AutonomyObservation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_race_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, race_interfaces, msg, AutonomyObservation)();

#ifdef __cplusplus
}
#endif

#endif  // RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
