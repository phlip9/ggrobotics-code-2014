/*
 * Wires commands to operator inputs.
 */

#include "OI.h"

#include "Config.h"
#include "Logging.h"

OI::OI()
    : drive_stick(CONFIG::JoystickDrive()) {

  log_info("OI()");
}

OI::~OI() {
  log_info("~OI()");
}

// Wires the buttons, joysticks, and SmartDashboard controls to their
// respective commands.
void OI::init() {
  log_info("init()");
  // TODO: Add SmartDashboard controls

}
