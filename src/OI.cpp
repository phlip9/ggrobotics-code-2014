/*
 * Wires commands to operator inputs.
 */

#include "OI.h"

#include "Commands/GyroToggle.h"
#include "Config.h"
#include "Logging.h"

OI::OI()
    : drive_stick(CONFIG::JoystickDrive()),
      button_gyro_toggle(&drive_stick, 2) {

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

  button_gyro_toggle.WhenReleased(new GyroToggle());
}
