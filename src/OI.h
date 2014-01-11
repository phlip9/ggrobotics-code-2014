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

  JoystickButton turn_left_button;
  JoystickButton turn_right_button;

};

#endif
