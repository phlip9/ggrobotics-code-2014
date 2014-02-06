#include "WheelMotorOn.h"

#include "Commands/Command.h"

#include "../Robot.h"
#include "../Logging.h"

WheelMotorOn::WheelMotorOn()
  : Command("WheelMotorOn") {

  log_debug("WheelMotorOn()");
}

void WheelMotorOn::Initialize() {}

void WheelMotorOn::Execute() {
  log_info("Execute() - Spinning Wheel Motor");
  Robot::hardware_map()->wheel_motor.Set(1.0);
}

bool WheelMotorOn::IsFinished() {
  return false;
}

void WheelMotorOn::End() {
  log_debug("End()");
  Robot::hardware_map()->wheel_motor.Set(0.0);
}

void WheelMotorOn::Interrupted() {
  log_debug("Interrupted()");
  Robot::hardware_map()->wheel_motor.Set(0.0);
}
