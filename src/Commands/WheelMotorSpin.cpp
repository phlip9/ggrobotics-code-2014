#include "WheelMotorSpin.h"

#include "../Subsystems/MotorSubsystem.h"

#include "../Config.h"
#include "../Robot.h"
#include "../Logging.h"

WheelMotorSpin::WheelMotorSpin(Direction direction)
  : Command("WheelMotorSpin"),
    m_direction(direction) {

  log_debug("WheelMotorSpin(%s)", str_direction(m_direction));
  Requires(Robot::arm_wheels());
}

WheelMotorSpin::~WheelMotorSpin() {}

void WheelMotorSpin::Initialize() {}

void WheelMotorSpin::Execute() {
  Robot::arm_wheels()->move(m_direction);
}

bool WheelMotorSpin::IsFinished() {
  return false;
}

void WheelMotorSpin::End() {
  log_debug("End()");
  Robot::arm_wheels()->stop();
}

void WheelMotorSpin::Interrupted() {
  log_debug("Interrupted()");
  Robot::arm_wheels()->stop();
}
