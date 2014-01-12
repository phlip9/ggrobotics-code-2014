/*
 * Wires commands to operator inputs.
 */

#include "OI.h"

#include "Config.h"
#include "Logging.h"

OI::OI()
    : drive_stick(CONFIG::JoystickDrive()) {

}

// Wires the buttons, joysticks, and SmartDashboard controls to their
// respective commands.
void OI::init() {
  log_info("OI::init()");
  // TODO: Add SmartDashboard controls

}
