// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from race_interfaces:msg/AutonomyObservation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "race_interfaces/msg/autonomy_observation.hpp"


#ifndef RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__STRUCT_HPP_
#define RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__race_interfaces__msg__AutonomyObservation __attribute__((deprecated))
#else
# define DEPRECATED__race_interfaces__msg__AutonomyObservation __declspec(deprecated)
#endif

namespace race_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AutonomyObservation_
{
  using Type = AutonomyObservation_<ContainerAllocator>;

  explicit AutonomyObservation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->perception_valid = false;
      this->imu_valid = false;
      this->speed_valid = false;
      this->stop_detected = false;
      this->traffic_light = 0;
      this->pitch_deg = 0.0f;
      this->roll_deg = 0.0f;
      this->yaw_deg = 0.0f;
      this->speed_kph = 0.0f;
    }
  }

  explicit AutonomyObservation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->perception_valid = false;
      this->imu_valid = false;
      this->speed_valid = false;
      this->stop_detected = false;
      this->traffic_light = 0;
      this->pitch_deg = 0.0f;
      this->roll_deg = 0.0f;
      this->yaw_deg = 0.0f;
      this->speed_kph = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _perception_valid_type =
    bool;
  _perception_valid_type perception_valid;
  using _imu_valid_type =
    bool;
  _imu_valid_type imu_valid;
  using _speed_valid_type =
    bool;
  _speed_valid_type speed_valid;
  using _stop_detected_type =
    bool;
  _stop_detected_type stop_detected;
  using _traffic_light_type =
    uint8_t;
  _traffic_light_type traffic_light;
  using _pitch_deg_type =
    float;
  _pitch_deg_type pitch_deg;
  using _roll_deg_type =
    float;
  _roll_deg_type roll_deg;
  using _yaw_deg_type =
    float;
  _yaw_deg_type yaw_deg;
  using _speed_kph_type =
    float;
  _speed_kph_type speed_kph;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__perception_valid(
    const bool & _arg)
  {
    this->perception_valid = _arg;
    return *this;
  }
  Type & set__imu_valid(
    const bool & _arg)
  {
    this->imu_valid = _arg;
    return *this;
  }
  Type & set__speed_valid(
    const bool & _arg)
  {
    this->speed_valid = _arg;
    return *this;
  }
  Type & set__stop_detected(
    const bool & _arg)
  {
    this->stop_detected = _arg;
    return *this;
  }
  Type & set__traffic_light(
    const uint8_t & _arg)
  {
    this->traffic_light = _arg;
    return *this;
  }
  Type & set__pitch_deg(
    const float & _arg)
  {
    this->pitch_deg = _arg;
    return *this;
  }
  Type & set__roll_deg(
    const float & _arg)
  {
    this->roll_deg = _arg;
    return *this;
  }
  Type & set__yaw_deg(
    const float & _arg)
  {
    this->yaw_deg = _arg;
    return *this;
  }
  Type & set__speed_kph(
    const float & _arg)
  {
    this->speed_kph = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t TRAFFIC_UNKNOWN =
    0u;
  static constexpr uint8_t TRAFFIC_RED =
    1u;
  static constexpr uint8_t TRAFFIC_YELLOW =
    2u;
  static constexpr uint8_t TRAFFIC_GREEN =
    3u;

  // pointer types
  using RawPtr =
    race_interfaces::msg::AutonomyObservation_<ContainerAllocator> *;
  using ConstRawPtr =
    const race_interfaces::msg::AutonomyObservation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<race_interfaces::msg::AutonomyObservation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<race_interfaces::msg::AutonomyObservation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      race_interfaces::msg::AutonomyObservation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<race_interfaces::msg::AutonomyObservation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      race_interfaces::msg::AutonomyObservation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<race_interfaces::msg::AutonomyObservation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<race_interfaces::msg::AutonomyObservation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<race_interfaces::msg::AutonomyObservation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__race_interfaces__msg__AutonomyObservation
    std::shared_ptr<race_interfaces::msg::AutonomyObservation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__race_interfaces__msg__AutonomyObservation
    std::shared_ptr<race_interfaces::msg::AutonomyObservation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AutonomyObservation_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->perception_valid != other.perception_valid) {
      return false;
    }
    if (this->imu_valid != other.imu_valid) {
      return false;
    }
    if (this->speed_valid != other.speed_valid) {
      return false;
    }
    if (this->stop_detected != other.stop_detected) {
      return false;
    }
    if (this->traffic_light != other.traffic_light) {
      return false;
    }
    if (this->pitch_deg != other.pitch_deg) {
      return false;
    }
    if (this->roll_deg != other.roll_deg) {
      return false;
    }
    if (this->yaw_deg != other.yaw_deg) {
      return false;
    }
    if (this->speed_kph != other.speed_kph) {
      return false;
    }
    return true;
  }
  bool operator!=(const AutonomyObservation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AutonomyObservation_

// alias to use template instance with default allocator
using AutonomyObservation =
  race_interfaces::msg::AutonomyObservation_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t AutonomyObservation_<ContainerAllocator>::TRAFFIC_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t AutonomyObservation_<ContainerAllocator>::TRAFFIC_RED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t AutonomyObservation_<ContainerAllocator>::TRAFFIC_YELLOW;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t AutonomyObservation_<ContainerAllocator>::TRAFFIC_GREEN;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace race_interfaces

#endif  // RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__STRUCT_HPP_
