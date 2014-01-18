/*
 * Maps hardware sensors, motors, solenoids, etc... to software objects.
 */

#ifndef _HARDWARE_MAP_H_
#define _HARDWARE_MAP_H_

#include "Talon.h"
#include "Gyro.h"

class HardwareMap {

 public:
  HardwareMap();
  ~HardwareMap();

  void init();

  // Drive motors
  Talon front_left_motor;
  Talon rear_left_motor;
  Talon front_right_motor;
  Talon rear_right_motor;

  // Drive gyro
  Gyro gyro;

};

#endif
