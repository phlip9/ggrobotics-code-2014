/*
 * Wires commands to operator inputs.
 */

#include "OI.h"

#include "Commands/GyroToggle.h"
#include "Config.h"
#include "Logging.h"

OI::OI()
    : drive_stick(CONFIG::drive_joystick),
      button_gyro_toggle(&drive_stick, CONFIG::button_gyro_toggle),
      wheel_motor_spin(&drive_stick, CONFIG::wheel_motor_spin),
      front_arm_motor_up(&drive_stick, CONFIG::front_arm_motor_up),
      front_arm_motor_down(&drive_stick, CONFIG::front_arm_motor_down),
      back_arm_motor_up(&drive_stick, CONFIG::back_arm_motor_up),
      back_arm_motor_down(&drive_stick, CONFIG::back_arm_motor_down) {

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
