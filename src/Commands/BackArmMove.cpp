#include "BackArmMove.h"

#include "../Subsystems/MotorSubsystem.h"

#include "../Robot.h"
#include "../Logging.h"

BackArmMove::BackArmMove(Direction direction)
  : Command("BackArmMove"),
    m_direction(direction) {

  log_debug("BackArmMove(%s)", str_direction(direction));
  Requires(Robot::back_arm());
}

void BackArmMove::Initialize() {}

void BackArmMove::Execute() {
  Robot::back_arm()->move(m_direction);
}

bool BackArmMove::IsFinished() {
  return false;
}

void BackArmMove::End() {
  log_debug("End()");
  Robot::back_arm()->stop();
}

void BackArmMove::Interrupted() {
  log_debug("Interrupted()");
  Robot::back_arm()->stop();
}
