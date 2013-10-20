/*
 * Maps hardware sensors, motors, solenoids, etc... to software objects.
 */

#ifndef _HARDWARE_MAP_H
#define _HARDWARE_MAP_H

#include "WPILib.h"

class HardwareMap {

 public:
  Jaguar front_left_motor;
  Jaguar front_right_motor;
  Jaguar rear_left_motor;
  Jaguar rear_right_motor;

  RobotDrive drivetrain;

  Solenoid hang_solenoid_left;
  Solenoid hang_solenoid_right;

  HardwareMap();
  ~HardwareMap();

  void AddToLiveWindow();

}

#endif
