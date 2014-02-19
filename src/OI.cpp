/*
 * Wires commands to operator inputs.
 */

#include "OI.h"

#include "Commands/Command.h"

#include "Robot.h"
#include "Commands/WheelMotorSpin.h"
#include "Commands/FrontArmMove.h"
#include "Commands/Shoot.h"
#include "Config.h"
#include "Logging.h"

OI::OI()
  : joystick_1(CONFIG::INPUT::joystick_1),
    button_wheel_spin_forward(&joystick_1, CONFIG::INPUT::arm_wheel_forward),
    button_wheel_spin_backward(&joystick_1, CONFIG::INPUT::arm_wheel_backward),
    button_front_arm_up(&joystick_1, CONFIG::INPUT::front_arm_up),
    button_front_arm_down(&joystick_1, CONFIG::INPUT::front_arm_down),
    button_shoot(&joystick_1, CONFIG::INPUT::shoot){

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

  button_wheel_spin_forward.WhileHeld(new WheelMotorSpin(Direction::UP));
  button_wheel_spin_backward.WhileHeld(new WheelMotorSpin(Direction::DOWN));

  button_front_arm_up.WhileHeld(new FrontArmMove(Direction::UP));
  button_front_arm_down.WhileHeld(new FrontArmMove(Direction::DOWN));

  button_shoot.WhenReleased(new Shoot());
}
