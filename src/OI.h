/*
 * Wires commands to operator inputs.
 */

#ifndef _OI_H_
#define _OI_H_

#include "Joystick.h"
#include "Buttons/JoystickButton.h"

class OI {

 public:
  OI();
  ~OI();

  void init();

  Joystick drive_stick;

  JoystickButton button_gyro_toggle;

  JoystickButton wheel_motor_spin;

  JoystickButton front_arm_motor_up;
  JoystickButton front_arm_motor_down;

  JoystickButton back_arm_motor_up;
  JoystickButton back_arm_motor_down;

};

#endif
