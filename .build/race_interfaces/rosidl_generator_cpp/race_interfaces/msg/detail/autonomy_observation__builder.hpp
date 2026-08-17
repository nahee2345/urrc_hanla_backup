// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from race_interfaces:msg/AutonomyObservation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "race_interfaces/msg/autonomy_observation.hpp"


#ifndef RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__BUILDER_HPP_
#define RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "race_interfaces/msg/detail/autonomy_observation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace race_interfaces
{

namespace msg
{

namespace builder
{

class Init_AutonomyObservation_speed_kph
{
public:
  explicit Init_AutonomyObservation_speed_kph(::race_interfaces::msg::AutonomyObservation & msg)
  : msg_(msg)
  {}
  ::race_interfaces::msg::AutonomyObservation speed_kph(::race_interfaces::msg::AutonomyObservation::_speed_kph_type arg)
  {
    msg_.speed_kph = std::move(arg);
    return std::move(msg_);
  }

private:
  ::race_interfaces::msg::AutonomyObservation msg_;
};

class Init_AutonomyObservation_yaw_deg
{
public:
  explicit Init_AutonomyObservation_yaw_deg(::race_interfaces::msg::AutonomyObservation & msg)
  : msg_(msg)
  {}
  Init_AutonomyObservation_speed_kph yaw_deg(::race_interfaces::msg::AutonomyObservation::_yaw_deg_type arg)
  {
    msg_.yaw_deg = std::move(arg);
    return Init_AutonomyObservation_speed_kph(msg_);
  }

private:
  ::race_interfaces::msg::AutonomyObservation msg_;
};

class Init_AutonomyObservation_roll_deg
{
public:
  explicit Init_AutonomyObservation_roll_deg(::race_interfaces::msg::AutonomyObservation & msg)
  : msg_(msg)
  {}
  Init_AutonomyObservation_yaw_deg roll_deg(::race_interfaces::msg::AutonomyObservation::_roll_deg_type arg)
  {
    msg_.roll_deg = std::move(arg);
    return Init_AutonomyObservation_yaw_deg(msg_);
  }

private:
  ::race_interfaces::msg::AutonomyObservation msg_;
};

class Init_AutonomyObservation_pitch_deg
{
public:
  explicit Init_AutonomyObservation_pitch_deg(::race_interfaces::msg::AutonomyObservation & msg)
  : msg_(msg)
  {}
  Init_AutonomyObservation_roll_deg pitch_deg(::race_interfaces::msg::AutonomyObservation::_pitch_deg_type arg)
  {
    msg_.pitch_deg = std::move(arg);
    return Init_AutonomyObservation_roll_deg(msg_);
  }

private:
  ::race_interfaces::msg::AutonomyObservation msg_;
};

class Init_AutonomyObservation_traffic_light
{
public:
  explicit Init_AutonomyObservation_traffic_light(::race_interfaces::msg::AutonomyObservation & msg)
  : msg_(msg)
  {}
  Init_AutonomyObservation_pitch_deg traffic_light(::race_interfaces::msg::AutonomyObservation::_traffic_light_type arg)
  {
    msg_.traffic_light = std::move(arg);
    return Init_AutonomyObservation_pitch_deg(msg_);
  }

private:
  ::race_interfaces::msg::AutonomyObservation msg_;
};

class Init_AutonomyObservation_stop_detected
{
public:
  explicit Init_AutonomyObservation_stop_detected(::race_interfaces::msg::AutonomyObservation & msg)
  : msg_(msg)
  {}
  Init_AutonomyObservation_traffic_light stop_detected(::race_interfaces::msg::AutonomyObservation::_stop_detected_type arg)
  {
    msg_.stop_detected = std::move(arg);
    return Init_AutonomyObservation_traffic_light(msg_);
  }

private:
  ::race_interfaces::msg::AutonomyObservation msg_;
};

class Init_AutonomyObservation_speed_valid
{
public:
  explicit Init_AutonomyObservation_speed_valid(::race_interfaces::msg::AutonomyObservation & msg)
  : msg_(msg)
  {}
  Init_AutonomyObservation_stop_detected speed_valid(::race_interfaces::msg::AutonomyObservation::_speed_valid_type arg)
  {
    msg_.speed_valid = std::move(arg);
    return Init_AutonomyObservation_stop_detected(msg_);
  }

private:
  ::race_interfaces::msg::AutonomyObservation msg_;
};

class Init_AutonomyObservation_imu_valid
{
public:
  explicit Init_AutonomyObservation_imu_valid(::race_interfaces::msg::AutonomyObservation & msg)
  : msg_(msg)
  {}
  Init_AutonomyObservation_speed_valid imu_valid(::race_interfaces::msg::AutonomyObservation::_imu_valid_type arg)
  {
    msg_.imu_valid = std::move(arg);
    return Init_AutonomyObservation_speed_valid(msg_);
  }

private:
  ::race_interfaces::msg::AutonomyObservation msg_;
};

class Init_AutonomyObservation_perception_valid
{
public:
  explicit Init_AutonomyObservation_perception_valid(::race_interfaces::msg::AutonomyObservation & msg)
  : msg_(msg)
  {}
  Init_AutonomyObservation_imu_valid perception_valid(::race_interfaces::msg::AutonomyObservation::_perception_valid_type arg)
  {
    msg_.perception_valid = std::move(arg);
    return Init_AutonomyObservation_imu_valid(msg_);
  }

private:
  ::race_interfaces::msg::AutonomyObservation msg_;
};

class Init_AutonomyObservation_header
{
public:
  Init_AutonomyObservation_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AutonomyObservation_perception_valid header(::race_interfaces::msg::AutonomyObservation::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_AutonomyObservation_perception_valid(msg_);
  }

private:
  ::race_interfaces::msg::AutonomyObservation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::race_interfaces::msg::AutonomyObservation>()
{
  return race_interfaces::msg::builder::Init_AutonomyObservation_header();
}

}  // namespace race_interfaces

#endif  // RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__BUILDER_HPP_
