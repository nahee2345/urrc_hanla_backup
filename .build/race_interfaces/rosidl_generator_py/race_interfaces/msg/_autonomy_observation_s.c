// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from race_interfaces:msg/AutonomyObservation.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "race_interfaces/msg/detail/autonomy_observation__struct.h"
#include "race_interfaces/msg/detail/autonomy_observation__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool race_interfaces__msg__autonomy_observation__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[62];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("race_interfaces.msg._autonomy_observation.AutonomyObservation", full_classname_dest, 61) == 0);
  }
  race_interfaces__msg__AutonomyObservation * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // perception_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "perception_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->perception_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // imu_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "imu_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->imu_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // speed_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->speed_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // stop_detected
    PyObject * field = PyObject_GetAttrString(_pymsg, "stop_detected");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->stop_detected = (Py_True == field);
    Py_DECREF(field);
  }
  {  // traffic_light
    PyObject * field = PyObject_GetAttrString(_pymsg, "traffic_light");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->traffic_light = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // pitch_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // roll_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "roll_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->roll_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed_kph
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_kph");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_kph = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * race_interfaces__msg__autonomy_observation__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AutonomyObservation */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("race_interfaces.msg._autonomy_observation");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AutonomyObservation");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  race_interfaces__msg__AutonomyObservation * ros_message = (race_interfaces__msg__AutonomyObservation *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // perception_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->perception_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "perception_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // imu_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->imu_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "imu_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->speed_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // stop_detected
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->stop_detected ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "stop_detected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // traffic_light
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->traffic_light);
    {
      int rc = PyObject_SetAttrString(_pymessage, "traffic_light", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // roll_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->roll_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "roll_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_kph
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_kph);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_kph", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
