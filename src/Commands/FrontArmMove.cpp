#include "FrontArmMove.h"

#include "../Subsystems/FrontArm.h"

#include "../Robot.h"
#include "../Logging.h"

FrontArmMove::FrontArmMove(Direction direction)
  : Command("FrontArmMove"),
    m_direction(direction) {

  log_debug("FrontArmMove(%s)", str_direction(direction));
  Requires(Robot::front_arm());
}

void FrontArmMove::Initialize() {}

void FrontArmMove::Execute() {
  Robot::front_arm()->move(m_direction);
}

bool FrontArmMove::IsFinished() {
  return false;
}

void FrontArmMove::End() {
  log_debug("End()");
  Robot::front_arm()->stop();
}

void FrontArmMove::Interrupted() {
  log_debug("Interrupted()");
  Robot::front_arm()->stop();
}
