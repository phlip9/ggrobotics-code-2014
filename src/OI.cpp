/*
 * Wires commands to operator inputs.
 */

#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"

#include "Commands/MotorMove.h"
#include "Commands/Shoot.h"
#include "Robot.h"
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
void OI::init(MotorSubsystem *arm_wheel, MotorSubsystem *front_arm, ShooterSubsystem *shooter) {
  log_info("init()");
  // TODO: Add SmartDashboard controls

  button_wheel_spin_forward.WhileHeld(new MotorMove("WheelMotorSpin", arm_wheel, Direction::UP));
  button_wheel_spin_backward.WhileHeld(new MotorMove("WheelMotorSpin", arm_wheel, Direction::DOWN));

  button_front_arm_up.WhileHeld(new MotorMove("FrontArmMove", front_arm, Direction::UP));
  button_front_arm_down.WhileHeld(new MotorMove("FrontArmMove", front_arm, Direction::DOWN));

  button_shoot.WhenReleased(new Shoot(shooter));
}

void OI::UpdateSmartDashboard() {
  SmartDashboard::PutNumber("Joystick 1 X Axis", joystick_1.GetX());
  SmartDashboard::PutNumber("Joystick 1 Y Axis", joystick_1.GetY());
  SmartDashboard::PutNumber("Joystick 1 Twist", joystick_1.GetThrottle());
  SmartDashboard::PutNumber("Joystick 1 Throttle", joystick_1.GetTwist());
}
