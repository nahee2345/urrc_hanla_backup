#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "race_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__race_interfaces__msg__AutonomyObservation() -> *const std::ffi::c_void;
}

#[link(name = "race_interfaces__rosidl_generator_c")]
extern "C" {
    fn race_interfaces__msg__AutonomyObservation__init(msg: *mut AutonomyObservation) -> bool;
    fn race_interfaces__msg__AutonomyObservation__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AutonomyObservation>, size: usize) -> bool;
    fn race_interfaces__msg__AutonomyObservation__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AutonomyObservation>);
    fn race_interfaces__msg__AutonomyObservation__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AutonomyObservation>, out_seq: *mut rosidl_runtime_rs::Sequence<AutonomyObservation>) -> bool;
}

// Corresponds to race_interfaces__msg__AutonomyObservation
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AutonomyObservation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub perception_valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub imu_valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed_valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stop_detected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub traffic_light: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pitch_deg: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub roll_deg: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub yaw_deg: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed_kph: f32,

}

impl AutonomyObservation {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRAFFIC_UNKNOWN: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRAFFIC_RED: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRAFFIC_YELLOW: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRAFFIC_GREEN: u8 = 3;

}


impl Default for AutonomyObservation {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !race_interfaces__msg__AutonomyObservation__init(&mut msg as *mut _) {
        panic!("Call to race_interfaces__msg__AutonomyObservation__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AutonomyObservation {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { race_interfaces__msg__AutonomyObservation__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { race_interfaces__msg__AutonomyObservation__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { race_interfaces__msg__AutonomyObservation__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AutonomyObservation {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AutonomyObservation where Self: Sized {
  const TYPE_NAME: &'static str = "race_interfaces/msg/AutonomyObservation";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__race_interfaces__msg__AutonomyObservation() }
  }
}


#[link(name = "race_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__race_interfaces__msg__PathState() -> *const std::ffi::c_void;
}

#[link(name = "race_interfaces__rosidl_generator_c")]
extern "C" {
    fn race_interfaces__msg__PathState__init(msg: *mut PathState) -> bool;
    fn race_interfaces__msg__PathState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PathState>, size: usize) -> bool;
    fn race_interfaces__msg__PathState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PathState>);
    fn race_interfaces__msg__PathState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PathState>, out_seq: *mut rosidl_runtime_rs::Sequence<PathState>) -> bool;
}

// Corresponds to race_interfaces__msg__PathState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PathState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mode: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub path: nav_msgs::msg::rmw::Path,

}



impl Default for PathState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !race_interfaces__msg__PathState__init(&mut msg as *mut _) {
        panic!("Call to race_interfaces__msg__PathState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PathState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { race_interfaces__msg__PathState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { race_interfaces__msg__PathState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { race_interfaces__msg__PathState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PathState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PathState where Self: Sized {
  const TYPE_NAME: &'static str = "race_interfaces/msg/PathState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__race_interfaces__msg__PathState() }
  }
}


