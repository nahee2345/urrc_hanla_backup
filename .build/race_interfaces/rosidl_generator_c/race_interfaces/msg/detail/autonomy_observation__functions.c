// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from race_interfaces:msg/AutonomyObservation.idl
// generated code does not contain a copyright notice
#include "race_interfaces/msg/detail/autonomy_observation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
race_interfaces__msg__AutonomyObservation__init(race_interfaces__msg__AutonomyObservation * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    race_interfaces__msg__AutonomyObservation__fini(msg);
    return false;
  }
  // perception_valid
  // imu_valid
  // speed_valid
  // stop_detected
  // traffic_light
  // pitch_deg
  // roll_deg
  // yaw_deg
  // speed_kph
  return true;
}

void
race_interfaces__msg__AutonomyObservation__fini(race_interfaces__msg__AutonomyObservation * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // perception_valid
  // imu_valid
  // speed_valid
  // stop_detected
  // traffic_light
  // pitch_deg
  // roll_deg
  // yaw_deg
  // speed_kph
}

bool
race_interfaces__msg__AutonomyObservation__are_equal(const race_interfaces__msg__AutonomyObservation * lhs, const race_interfaces__msg__AutonomyObservation * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // perception_valid
  if (lhs->perception_valid != rhs->perception_valid) {
    return false;
  }
  // imu_valid
  if (lhs->imu_valid != rhs->imu_valid) {
    return false;
  }
  // speed_valid
  if (lhs->speed_valid != rhs->speed_valid) {
    return false;
  }
  // stop_detected
  if (lhs->stop_detected != rhs->stop_detected) {
    return false;
  }
  // traffic_light
  if (lhs->traffic_light != rhs->traffic_light) {
    return false;
  }
  // pitch_deg
  if (lhs->pitch_deg != rhs->pitch_deg) {
    return false;
  }
  // roll_deg
  if (lhs->roll_deg != rhs->roll_deg) {
    return false;
  }
  // yaw_deg
  if (lhs->yaw_deg != rhs->yaw_deg) {
    return false;
  }
  // speed_kph
  if (lhs->speed_kph != rhs->speed_kph) {
    return false;
  }
  return true;
}

bool
race_interfaces__msg__AutonomyObservation__copy(
  const race_interfaces__msg__AutonomyObservation * input,
  race_interfaces__msg__AutonomyObservation * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // perception_valid
  output->perception_valid = input->perception_valid;
  // imu_valid
  output->imu_valid = input->imu_valid;
  // speed_valid
  output->speed_valid = input->speed_valid;
  // stop_detected
  output->stop_detected = input->stop_detected;
  // traffic_light
  output->traffic_light = input->traffic_light;
  // pitch_deg
  output->pitch_deg = input->pitch_deg;
  // roll_deg
  output->roll_deg = input->roll_deg;
  // yaw_deg
  output->yaw_deg = input->yaw_deg;
  // speed_kph
  output->speed_kph = input->speed_kph;
  return true;
}

race_interfaces__msg__AutonomyObservation *
race_interfaces__msg__AutonomyObservation__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  race_interfaces__msg__AutonomyObservation * msg = (race_interfaces__msg__AutonomyObservation *)allocator.allocate(sizeof(race_interfaces__msg__AutonomyObservation), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(race_interfaces__msg__AutonomyObservation));
  bool success = race_interfaces__msg__AutonomyObservation__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
race_interfaces__msg__AutonomyObservation__destroy(race_interfaces__msg__AutonomyObservation * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    race_interfaces__msg__AutonomyObservation__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
race_interfaces__msg__AutonomyObservation__Sequence__init(race_interfaces__msg__AutonomyObservation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  race_interfaces__msg__AutonomyObservation * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(race_interfaces__msg__AutonomyObservation)) {
      return false;
    }
    data = (race_interfaces__msg__AutonomyObservation *)allocator.zero_allocate(size, sizeof(race_interfaces__msg__AutonomyObservation), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = race_interfaces__msg__AutonomyObservation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        race_interfaces__msg__AutonomyObservation__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
race_interfaces__msg__AutonomyObservation__Sequence__fini(race_interfaces__msg__AutonomyObservation__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      race_interfaces__msg__AutonomyObservation__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

race_interfaces__msg__AutonomyObservation__Sequence *
race_interfaces__msg__AutonomyObservation__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  race_interfaces__msg__AutonomyObservation__Sequence * array = (race_interfaces__msg__AutonomyObservation__Sequence *)allocator.allocate(sizeof(race_interfaces__msg__AutonomyObservation__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = race_interfaces__msg__AutonomyObservation__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
race_interfaces__msg__AutonomyObservation__Sequence__destroy(race_interfaces__msg__AutonomyObservation__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    race_interfaces__msg__AutonomyObservation__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
race_interfaces__msg__AutonomyObservation__Sequence__are_equal(const race_interfaces__msg__AutonomyObservation__Sequence * lhs, const race_interfaces__msg__AutonomyObservation__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!race_interfaces__msg__AutonomyObservation__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
race_interfaces__msg__AutonomyObservation__Sequence__copy(
  const race_interfaces__msg__AutonomyObservation__Sequence * input,
  race_interfaces__msg__AutonomyObservation__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(race_interfaces__msg__AutonomyObservation)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(race_interfaces__msg__AutonomyObservation);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    race_interfaces__msg__AutonomyObservation * data =
      (race_interfaces__msg__AutonomyObservation *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!race_interfaces__msg__AutonomyObservation__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          race_interfaces__msg__AutonomyObservation__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!race_interfaces__msg__AutonomyObservation__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
