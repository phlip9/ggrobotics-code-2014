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

  void Init();

 private:
  // Joysticks
  Joystick drive_stick;

  // Buttons on Joysticks
  JoystickButton solenoid_up_button;
  JoystickButton solenoid_down_button;

  JoystickButton turn_left_button;
  JoystickButton turn_right_button;

};

#endif
