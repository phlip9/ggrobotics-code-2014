/*
 * Wires commands to operator inputs.
 */

#include "OI.h"

// Commands
#include "Commands/HookUp.h"
#include "Commands/HookDown.h"

#include "Commands/TurnLeft.h"
#include "Commands/TurnRight.h"

OI::OI()
    : drive_stick(1),
      solenoid_up_button(&drive_stick, 3),
      solenoid_down_button(&drive_stick, 2),
      turn_left_button(&drive_stick, 4),
      turn_right_button(&drive_stick, 5) {

}

// Wires the buttons, joysticks, and SmartDashboard controls to their
// respective commands.
void OI::Init() {
  // Ughh memory leaks... should probably free these Command objects somewhere.
  // But, I guess this class won't be deconstructed until the robot dies, so I
  // don't really care.
  solenoid_up_button.WhileHeld(new HookUp());
  solenoid_down_button.WhileHeld(new HookDown());

  turn_left_button.WhileHeld(new TurnLeft());
  turn_right_button.WhileHeld(new TurnRight());

  // TODO: Add SmartDashboard controls
}
