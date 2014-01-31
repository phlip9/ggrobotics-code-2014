#include "FrontArmMove.h"

#include "../Subsystems/FrontArm.h"

#include "../Robot.h"
#include "../Logging.h"

FrontArmMove::FrontArmMove(Direction direction)
  : Command("FrontArmMove"),
    m_direction(direction) {

  log_debug("WheelMotorOn()");
  Requires(Robot::front_arm());
}

void FrontArmMove::Initialize() {}

void FrontArmMove::Execute() {
  log_info("Execute() - Move front arm %s", m_direction == Direction::UP ? "UP" : "DOWN");
  Robot::front_arm()->move(m_direction);
}

bool FrontArmMove::IsFinished() {
  return false;
}

void FrontArmMove::End() {
  log_debug("End()");
}

void FrontArmMove::Interrupted() {}
