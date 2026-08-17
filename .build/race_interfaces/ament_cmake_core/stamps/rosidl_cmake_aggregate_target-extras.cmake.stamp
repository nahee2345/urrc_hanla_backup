# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target race_interfaces::race_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${race_interfaces_TARGETS}.
if(race_interfaces_TARGETS AND NOT TARGET race_interfaces::race_interfaces)
  add_library(race_interfaces::race_interfaces INTERFACE IMPORTED)
  set_target_properties(race_interfaces::race_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${race_interfaces_TARGETS}")
endif()
