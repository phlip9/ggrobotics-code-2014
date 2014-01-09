/*
 * Maps hardware sensors, motors, solenoids, etc... to software objects.
 */

#ifndef _HARDWARE_MAP_H
#define _HARDWARE_MAP_H

#include "WPILib.h"

class HardwareMap {

 public:

  Solenoid hang_solenoid_left;
  Solenoid hang_solenoid_right;

  HardwareMap();
  ~HardwareMap();

  void AddToLiveWindow();

}

#endif
