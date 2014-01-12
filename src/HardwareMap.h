/*
 * Maps hardware sensors, motors, solenoids, etc... to software objects.
 */

#ifndef _HARDWARE_MAP_H_
#define _HARDWARE_MAP_H_

class Jaguar;

class HardwareMap {

 public:
  HardwareMap();
  ~HardwareMap();

  void init();

  Jaguar* front_left_motor;
  Jaguar* rear_left_motor;
  Jaguar* front_right_motor;
  Jaguar* rear_right_motor;

};

#endif
