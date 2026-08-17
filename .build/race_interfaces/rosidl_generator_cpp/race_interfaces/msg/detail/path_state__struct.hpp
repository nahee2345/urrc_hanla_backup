// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from race_interfaces:msg/PathState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "race_interfaces/msg/path_state.hpp"


#ifndef RACE_INTERFACES__MSG__DETAIL__PATH_STATE__STRUCT_HPP_
#define RACE_INTERFACES__MSG__DETAIL__PATH_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'path'
#include "nav_msgs/msg/detail/path__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__race_interfaces__msg__PathState __attribute__((deprecated))
#else
# define DEPRECATED__race_interfaces__msg__PathState __declspec(deprecated)
#endif

namespace race_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PathState_
{
  using Type = PathState_<ContainerAllocator>;

  explicit PathState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    path(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->valid = false;
      this->confidence = 0.0f;
      this->mode = 0;
    }
  }

  explicit PathState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    path(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->valid = false;
      this->confidence = 0.0f;
      this->mode = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _valid_type =
    bool;
  _valid_type valid;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _mode_type =
    int8_t;
  _mode_type mode;
  using _path_type =
    nav_msgs::msg::Path_<ContainerAllocator>;
  _path_type path;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__valid(
    const bool & _arg)
  {
    this->valid = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__mode(
    const int8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__path(
    const nav_msgs::msg::Path_<ContainerAllocator> & _arg)
  {
    this->path = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    race_interfaces::msg::PathState_<ContainerAllocator> *;
  using ConstRawPtr =
    const race_interfaces::msg::PathState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<race_interfaces::msg::PathState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<race_interfaces::msg::PathState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      race_interfaces::msg::PathState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<race_interfaces::msg::PathState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      race_interfaces::msg::PathState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<race_interfaces::msg::PathState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<race_interfaces::msg::PathState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<race_interfaces::msg::PathState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__race_interfaces__msg__PathState
    std::shared_ptr<race_interfaces::msg::PathState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__race_interfaces__msg__PathState
    std::shared_ptr<race_interfaces::msg::PathState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->valid != other.valid) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->path != other.path) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathState_

// alias to use template instance with default allocator
using PathState =
  race_interfaces::msg::PathState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace race_interfaces

#endif  // RACE_INTERFACES__MSG__DETAIL__PATH_STATE__STRUCT_HPP_
