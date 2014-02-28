#include "FrontArmMove.h"

#include "../Subsystems/MotorSubsystem.h"
#include "../Robot.h"
#include "../Logging.h"

FrontArmMove::FrontArmMove(MotorSubsystem *front_arm, Direction direction)
  : Command("FrontArmMove"),
    m_front_arm(front_arm),
    m_direction(direction) {

  log_debug("FrontArmMove(%s)", str_direction(direction));
  Requires(front_arm);
}

FrontArmMove::~FrontArmMove() {}

void FrontArmMove::Initialize() {}

void FrontArmMove::Execute() {
  m_front_arm->move(m_direction);
}

bool FrontArmMove::IsFinished() {
  return false;
}

void FrontArmMove::End() {
  log_debug("End()");
  m_front_arm->stop();
}

void FrontArmMove::Interrupted() {
  log_debug("Interrupted()");
  m_front_arm->stop();
}
