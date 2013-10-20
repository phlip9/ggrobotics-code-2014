/*
 * Wires commands to operator inputs.
 */

#include "OI.h"

OI::OI()
    : drive_stick(1),
      solenoid_up_button(&drive_stick, 3),
      solenoid_down_button(&drive_stick, 2),
      turn_left_button(&drive_stick, 4),
      turn_right_button(&drive_stick, 5) {

}
