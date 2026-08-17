// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from race_interfaces:msg/AutonomyObservation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "race_interfaces/msg/detail/autonomy_observation__rosidl_typesupport_introspection_c.h"
#include "race_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "race_interfaces/msg/detail/autonomy_observation__functions.h"
#include "race_interfaces/msg/detail/autonomy_observation__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  race_interfaces__msg__AutonomyObservation__init(message_memory);
}

void race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_fini_function(void * message_memory)
{
  race_interfaces__msg__AutonomyObservation__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_message_member_array[10] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(race_interfaces__msg__AutonomyObservation, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "perception_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(race_interfaces__msg__AutonomyObservation, perception_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "imu_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(race_interfaces__msg__AutonomyObservation, imu_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(race_interfaces__msg__AutonomyObservation, speed_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stop_detected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(race_interfaces__msg__AutonomyObservation, stop_detected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "traffic_light",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(race_interfaces__msg__AutonomyObservation, traffic_light),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch_deg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(race_interfaces__msg__AutonomyObservation, pitch_deg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "roll_deg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(race_interfaces__msg__AutonomyObservation, roll_deg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw_deg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(race_interfaces__msg__AutonomyObservation, yaw_deg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed_kph",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(race_interfaces__msg__AutonomyObservation, speed_kph),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_message_members = {
  "race_interfaces__msg",  // message namespace
  "AutonomyObservation",  // message name
  10,  // number of fields
  sizeof(race_interfaces__msg__AutonomyObservation),
  false,  // has_any_key_member_
  race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_message_member_array,  // message members
  race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_init_function,  // function to initialize message memory (memory has to be allocated)
  race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_message_type_support_handle = {
  0,
  &race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_message_members,
  get_message_typesupport_handle_function,
  &race_interfaces__msg__AutonomyObservation__get_type_hash,
  &race_interfaces__msg__AutonomyObservation__get_type_description,
  &race_interfaces__msg__AutonomyObservation__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_race_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, race_interfaces, msg, AutonomyObservation)() {
  race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_message_type_support_handle.typesupport_identifier) {
    race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &race_interfaces__msg__AutonomyObservation__rosidl_typesupport_introspection_c__AutonomyObservation_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
