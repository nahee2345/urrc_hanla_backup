// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from race_interfaces:msg/PathState.idl
// generated code does not contain a copyright notice
#include "race_interfaces/msg/detail/path_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `path`
#include "nav_msgs/msg/detail/path__functions.h"

bool
race_interfaces__msg__PathState__init(race_interfaces__msg__PathState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    race_interfaces__msg__PathState__fini(msg);
    return false;
  }
  // valid
  // confidence
  // mode
  // path
  if (!nav_msgs__msg__Path__init(&msg->path)) {
    race_interfaces__msg__PathState__fini(msg);
    return false;
  }
  return true;
}

void
race_interfaces__msg__PathState__fini(race_interfaces__msg__PathState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // valid
  // confidence
  // mode
  // path
  nav_msgs__msg__Path__fini(&msg->path);
}

bool
race_interfaces__msg__PathState__are_equal(const race_interfaces__msg__PathState * lhs, const race_interfaces__msg__PathState * rhs)
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
  // valid
  if (lhs->valid != rhs->valid) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // path
  if (!nav_msgs__msg__Path__are_equal(
      &(lhs->path), &(rhs->path)))
  {
    return false;
  }
  return true;
}

bool
race_interfaces__msg__PathState__copy(
  const race_interfaces__msg__PathState * input,
  race_interfaces__msg__PathState * output)
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
  // valid
  output->valid = input->valid;
  // confidence
  output->confidence = input->confidence;
  // mode
  output->mode = input->mode;
  // path
  if (!nav_msgs__msg__Path__copy(
      &(input->path), &(output->path)))
  {
    return false;
  }
  return true;
}

race_interfaces__msg__PathState *
race_interfaces__msg__PathState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  race_interfaces__msg__PathState * msg = (race_interfaces__msg__PathState *)allocator.allocate(sizeof(race_interfaces__msg__PathState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(race_interfaces__msg__PathState));
  bool success = race_interfaces__msg__PathState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
race_interfaces__msg__PathState__destroy(race_interfaces__msg__PathState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    race_interfaces__msg__PathState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
race_interfaces__msg__PathState__Sequence__init(race_interfaces__msg__PathState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  race_interfaces__msg__PathState * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(race_interfaces__msg__PathState)) {
      return false;
    }
    data = (race_interfaces__msg__PathState *)allocator.zero_allocate(size, sizeof(race_interfaces__msg__PathState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = race_interfaces__msg__PathState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        race_interfaces__msg__PathState__fini(&data[i - 1]);
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
race_interfaces__msg__PathState__Sequence__fini(race_interfaces__msg__PathState__Sequence * array)
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
      race_interfaces__msg__PathState__fini(&array->data[i]);
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

race_interfaces__msg__PathState__Sequence *
race_interfaces__msg__PathState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  race_interfaces__msg__PathState__Sequence * array = (race_interfaces__msg__PathState__Sequence *)allocator.allocate(sizeof(race_interfaces__msg__PathState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = race_interfaces__msg__PathState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
race_interfaces__msg__PathState__Sequence__destroy(race_interfaces__msg__PathState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    race_interfaces__msg__PathState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
race_interfaces__msg__PathState__Sequence__are_equal(const race_interfaces__msg__PathState__Sequence * lhs, const race_interfaces__msg__PathState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!race_interfaces__msg__PathState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
race_interfaces__msg__PathState__Sequence__copy(
  const race_interfaces__msg__PathState__Sequence * input,
  race_interfaces__msg__PathState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(race_interfaces__msg__PathState)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(race_interfaces__msg__PathState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    race_interfaces__msg__PathState * data =
      (race_interfaces__msg__PathState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!race_interfaces__msg__PathState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          race_interfaces__msg__PathState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!race_interfaces__msg__PathState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
