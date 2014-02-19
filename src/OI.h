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

  Joystick joystick_1;

  JoystickButton button_wheel_spin_forward;
  JoystickButton button_wheel_spin_backward;

  JoystickButton button_front_arm_up;
  JoystickButton button_front_arm_down;

  JoystickButton button_shoot;
};

#endif
