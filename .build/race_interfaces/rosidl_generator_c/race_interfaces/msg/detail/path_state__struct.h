// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from race_interfaces:msg/PathState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "race_interfaces/msg/path_state.h"


#ifndef RACE_INTERFACES__MSG__DETAIL__PATH_STATE__STRUCT_H_
#define RACE_INTERFACES__MSG__DETAIL__PATH_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'path'
#include "nav_msgs/msg/detail/path__struct.h"

/// Struct defined in msg/PathState in the package race_interfaces.
typedef struct race_interfaces__msg__PathState
{
  std_msgs__msg__Header header;
  bool valid;
  float confidence;
  int8_t mode;
  nav_msgs__msg__Path path;
} race_interfaces__msg__PathState;

// Struct for a sequence of race_interfaces__msg__PathState.
typedef struct race_interfaces__msg__PathState__Sequence
{
  race_interfaces__msg__PathState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} race_interfaces__msg__PathState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RACE_INTERFACES__MSG__DETAIL__PATH_STATE__STRUCT_H_
