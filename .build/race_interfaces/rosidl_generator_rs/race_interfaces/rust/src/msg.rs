#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to race_interfaces__msg__AutonomyObservation

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AutonomyObservation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::AutonomyObservation::default())
  }
}

impl rosidl_runtime_rs::Message for AutonomyObservation {
  type RmwMsg = super::msg::rmw::AutonomyObservation;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        perception_valid: msg.perception_valid,
        imu_valid: msg.imu_valid,
        speed_valid: msg.speed_valid,
        stop_detected: msg.stop_detected,
        traffic_light: msg.traffic_light,
        pitch_deg: msg.pitch_deg,
        roll_deg: msg.roll_deg,
        yaw_deg: msg.yaw_deg,
        speed_kph: msg.speed_kph,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      perception_valid: msg.perception_valid,
      imu_valid: msg.imu_valid,
      speed_valid: msg.speed_valid,
      stop_detected: msg.stop_detected,
      traffic_light: msg.traffic_light,
      pitch_deg: msg.pitch_deg,
      roll_deg: msg.roll_deg,
      yaw_deg: msg.yaw_deg,
      speed_kph: msg.speed_kph,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      perception_valid: msg.perception_valid,
      imu_valid: msg.imu_valid,
      speed_valid: msg.speed_valid,
      stop_detected: msg.stop_detected,
      traffic_light: msg.traffic_light,
      pitch_deg: msg.pitch_deg,
      roll_deg: msg.roll_deg,
      yaw_deg: msg.yaw_deg,
      speed_kph: msg.speed_kph,
    }
  }
}


// Corresponds to race_interfaces__msg__PathState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PathState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


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
    pub path: nav_msgs::msg::Path,

}



impl Default for PathState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::PathState::default())
  }
}

impl rosidl_runtime_rs::Message for PathState {
  type RmwMsg = super::msg::rmw::PathState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        valid: msg.valid,
        confidence: msg.confidence,
        mode: msg.mode,
        path: nav_msgs::msg::Path::into_rmw_message(std::borrow::Cow::Owned(msg.path)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      valid: msg.valid,
      confidence: msg.confidence,
      mode: msg.mode,
        path: nav_msgs::msg::Path::into_rmw_message(std::borrow::Cow::Borrowed(&msg.path)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      valid: msg.valid,
      confidence: msg.confidence,
      mode: msg.mode,
      path: nav_msgs::msg::Path::from_rmw_message(msg.path),
    }
  }
}


