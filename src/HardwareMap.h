/*
 * Maps hardware sensors, motors, solenoids, etc... to software objects.
 */

#ifndef _HARDWARE_MAP_H_
#define _HARDWARE_MAP_H_

class SpeedController;

#include "Gyro.h"

class HardwareMap {

 public:
  HardwareMap();
  ~HardwareMap();

  void init();

  SpeedController* front_left_motor;
  SpeedController* rear_left_motor;
  SpeedController* front_right_motor;
  SpeedController* rear_right_motor;

  Gyro gyro;

};

#endif
