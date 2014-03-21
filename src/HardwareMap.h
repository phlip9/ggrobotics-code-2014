/*
 * Maps hardware sensors, motors, solenoids, etc... to software objects.
 */

#ifndef _HARDWARE_MAP_H_
#define _HARDWARE_MAP_H_

#include "Talon.h"
#include "Solenoid.h"
#include "Compressor.h"

class HardwareMap {
 public:
  HardwareMap();
  ~HardwareMap();

  // Adds the motors to the live window for use in test mode.
  void init();

  // Puts the current motor values on the SmartDashboard.
  void UpdateSmartDashboard();

  // Drive motors
  Talon front_left_motor;
  Talon rear_left_motor;
  Talon front_right_motor;
  Talon rear_right_motor;

  // Arm wheel spinning motor
  Talon wheel_motor;

  // Arm moving motor
  Talon front_arm_motor;

  // Shooter solenoids
  Solenoid launch_solenoid_right;
  Solenoid launch_solenoid_left;

  Compressor compressor;
};

#endif
