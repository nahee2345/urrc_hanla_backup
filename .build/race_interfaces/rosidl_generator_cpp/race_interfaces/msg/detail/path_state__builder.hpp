// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from race_interfaces:msg/PathState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "race_interfaces/msg/path_state.hpp"


#ifndef RACE_INTERFACES__MSG__DETAIL__PATH_STATE__BUILDER_HPP_
#define RACE_INTERFACES__MSG__DETAIL__PATH_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "race_interfaces/msg/detail/path_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace race_interfaces
{

namespace msg
{

namespace builder
{

class Init_PathState_path
{
public:
  explicit Init_PathState_path(::race_interfaces::msg::PathState & msg)
  : msg_(msg)
  {}
  ::race_interfaces::msg::PathState path(::race_interfaces::msg::PathState::_path_type arg)
  {
    msg_.path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::race_interfaces::msg::PathState msg_;
};

class Init_PathState_mode
{
public:
  explicit Init_PathState_mode(::race_interfaces::msg::PathState & msg)
  : msg_(msg)
  {}
  Init_PathState_path mode(::race_interfaces::msg::PathState::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_PathState_path(msg_);
  }

private:
  ::race_interfaces::msg::PathState msg_;
};

class Init_PathState_confidence
{
public:
  explicit Init_PathState_confidence(::race_interfaces::msg::PathState & msg)
  : msg_(msg)
  {}
  Init_PathState_mode confidence(::race_interfaces::msg::PathState::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_PathState_mode(msg_);
  }

private:
  ::race_interfaces::msg::PathState msg_;
};

class Init_PathState_valid
{
public:
  explicit Init_PathState_valid(::race_interfaces::msg::PathState & msg)
  : msg_(msg)
  {}
  Init_PathState_confidence valid(::race_interfaces::msg::PathState::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return Init_PathState_confidence(msg_);
  }

private:
  ::race_interfaces::msg::PathState msg_;
};

class Init_PathState_header
{
public:
  Init_PathState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathState_valid header(::race_interfaces::msg::PathState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PathState_valid(msg_);
  }

private:
  ::race_interfaces::msg::PathState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::race_interfaces::msg::PathState>()
{
  return race_interfaces::msg::builder::Init_PathState_header();
}

}  // namespace race_interfaces

#endif  // RACE_INTERFACES__MSG__DETAIL__PATH_STATE__BUILDER_HPP_
