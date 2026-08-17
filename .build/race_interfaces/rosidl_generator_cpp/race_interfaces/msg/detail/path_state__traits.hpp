// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from race_interfaces:msg/PathState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "race_interfaces/msg/path_state.hpp"


#ifndef RACE_INTERFACES__MSG__DETAIL__PATH_STATE__TRAITS_HPP_
#define RACE_INTERFACES__MSG__DETAIL__PATH_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "race_interfaces/msg/detail/path_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'path'
#include "nav_msgs/msg/detail/path__traits.hpp"

namespace race_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PathState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: valid
  {
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: path
  {
    out << "path: ";
    to_flow_style_yaml(msg.path, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PathState & msg,
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

  // member: valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path:\n";
    to_block_style_yaml(msg.path, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PathState & msg, bool use_flow_style = false)
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
  const race_interfaces::msg::PathState & msg,
  std::ostream & out, size_t indentation = 0)
{
  race_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use race_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const race_interfaces::msg::PathState & msg)
{
  return race_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<race_interfaces::msg::PathState>()
{
  return "race_interfaces::msg::PathState";
}

template<>
inline const char * name<race_interfaces::msg::PathState>()
{
  return "race_interfaces/msg/PathState";
}

template<>
struct has_fixed_size<race_interfaces::msg::PathState>
  : std::integral_constant<bool, has_fixed_size<nav_msgs::msg::Path>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<race_interfaces::msg::PathState>
  : std::integral_constant<bool, has_bounded_size<nav_msgs::msg::Path>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<race_interfaces::msg::PathState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RACE_INTERFACES__MSG__DETAIL__PATH_STATE__TRAITS_HPP_
