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

};

#endif
