// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from race_interfaces:msg/AutonomyObservation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "race_interfaces/msg/autonomy_observation.h"


#ifndef RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__STRUCT_H_
#define RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'TRAFFIC_UNKNOWN'.
enum
{
  race_interfaces__msg__AutonomyObservation__TRAFFIC_UNKNOWN = 0
};

/// Constant 'TRAFFIC_RED'.
enum
{
  race_interfaces__msg__AutonomyObservation__TRAFFIC_RED = 1
};

/// Constant 'TRAFFIC_YELLOW'.
enum
{
  race_interfaces__msg__AutonomyObservation__TRAFFIC_YELLOW = 2
};

/// Constant 'TRAFFIC_GREEN'.
enum
{
  race_interfaces__msg__AutonomyObservation__TRAFFIC_GREEN = 3
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/AutonomyObservation in the package race_interfaces.
typedef struct race_interfaces__msg__AutonomyObservation
{
  std_msgs__msg__Header header;
  bool perception_valid;
  bool imu_valid;
  bool speed_valid;
  bool stop_detected;
  uint8_t traffic_light;
  float pitch_deg;
  float roll_deg;
  float yaw_deg;
  float speed_kph;
} race_interfaces__msg__AutonomyObservation;

// Struct for a sequence of race_interfaces__msg__AutonomyObservation.
typedef struct race_interfaces__msg__AutonomyObservation__Sequence
{
  race_interfaces__msg__AutonomyObservation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} race_interfaces__msg__AutonomyObservation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__STRUCT_H_
