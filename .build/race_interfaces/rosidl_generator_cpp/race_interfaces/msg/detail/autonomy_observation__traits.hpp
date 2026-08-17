// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from race_interfaces:msg/AutonomyObservation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "race_interfaces/msg/autonomy_observation.hpp"


#ifndef RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__TRAITS_HPP_
#define RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "race_interfaces/msg/detail/autonomy_observation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace race_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AutonomyObservation & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: perception_valid
  {
    out << "perception_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.perception_valid, out);
    out << ", ";
  }

  // member: imu_valid
  {
    out << "imu_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.imu_valid, out);
    out << ", ";
  }

  // member: speed_valid
  {
    out << "speed_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_valid, out);
    out << ", ";
  }

  // member: stop_detected
  {
    out << "stop_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.stop_detected, out);
    out << ", ";
  }

  // member: traffic_light
  {
    out << "traffic_light: ";
    rosidl_generator_traits::value_to_yaml(msg.traffic_light, out);
    out << ", ";
  }

  // member: pitch_deg
  {
    out << "pitch_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_deg, out);
    out << ", ";
  }

  // member: roll_deg
  {
    out << "roll_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_deg, out);
    out << ", ";
  }

  // member: yaw_deg
  {
    out << "yaw_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_deg, out);
    out << ", ";
  }

  // member: speed_kph
  {
    out << "speed_kph: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_kph, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AutonomyObservation & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: perception_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "perception_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.perception_valid, out);
    out << "\n";
  }

  // member: imu_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imu_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.imu_valid, out);
    out << "\n";
  }

  // member: speed_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_valid, out);
    out << "\n";
  }

  // member: stop_detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stop_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.stop_detected, out);
    out << "\n";
  }

  // member: traffic_light
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "traffic_light: ";
    rosidl_generator_traits::value_to_yaml(msg.traffic_light, out);
    out << "\n";
  }

  // member: pitch_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_deg, out);
    out << "\n";
  }

  // member: roll_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_deg, out);
    out << "\n";
  }

  // member: yaw_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_deg, out);
    out << "\n";
  }

  // member: speed_kph
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_kph: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_kph, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AutonomyObservation & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace race_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use race_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const race_interfaces::msg::AutonomyObservation & msg,
  std::ostream & out, size_t indentation = 0)
{
  race_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use race_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const race_interfaces::msg::AutonomyObservation & msg)
{
  return race_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<race_interfaces::msg::AutonomyObservation>()
{
  return "race_interfaces::msg::AutonomyObservation";
}

template<>
inline const char * name<race_interfaces::msg::AutonomyObservation>()
{
  return "race_interfaces/msg/AutonomyObservation";
}

template<>
struct has_fixed_size<race_interfaces::msg::AutonomyObservation>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<race_interfaces::msg::AutonomyObservation>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<race_interfaces::msg::AutonomyObservation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RACE_INTERFACES__MSG__DETAIL__AUTONOMY_OBSERVATION__TRAITS_HPP_
