/*
 * Wires commands to operator inputs.
 */

#include "OI.h"

#include "Config.h"
//#include "Commands/TurnLeft.h"
//#include "Commands/TurnRight.h"

OI::OI()
    : drive_stick(CONFIG::JOYSTICK_DRIVE),
      turn_left_button(&drive_stick, CONFIG::BUTTON_TURN_LEFT),
      turn_right_button(&drive_stick, CONFIG::BUTTON_TURN_RIGHT) {

}

// Wires the buttons, joysticks, and SmartDashboard controls to their
// respective commands.
void OI::init() {

  // TODO: Implemenet Turn commands
  //turn_left_button.WhileHeld(new TurnLeft());
  //turn_right_button.WhileHeld(new TurnRight());

  // TODO: Add SmartDashboard controls
}
