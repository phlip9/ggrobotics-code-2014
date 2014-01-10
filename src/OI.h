/*
 * Wires commands to operator inputs.
 */

#ifndef _OI_H
#define _OI_H

#include "Joystick.h"
#include "Buttons/JoystickButton.h"

class OI {

 public:
  OI();
  ~OI();

  Joystick drive_stick;

  JoystickButton turn_left_button;
  JoystickButton turn_right_button;

  void init();

};

#endif
