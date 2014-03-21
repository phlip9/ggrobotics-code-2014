#include "MotorMove.h"

#include "../Subsystems/MotorSubsystem.h"

#include "../Robot.h"
#include "../Logging.h"

MotorMove::MotorMove(const char* name, MotorSubsystem *subsystem, Direction direction)
  : Command(name),
    m_name(name),
    m_subsystem(subsystem),
    m_direction(direction) {

  log_debug("%s(%s)", name, str_direction(direction));
  Requires(subsystem);
}

MotorMove::~MotorMove() { }

void MotorMove::Initialize() { }

void MotorMove::Execute() {
  m_subsystem->move(m_direction);
}

bool MotorMove::IsFinished() {
  return false;
}

void MotorMove::End() {
  log_debug("%s End()", m_name);
  m_subsystem->stop();
}

void MotorMove::Interrupted() {
  log_debug("%s Interrupted()", m_name);
  m_subsystem->stop();
}
