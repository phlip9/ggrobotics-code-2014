#include "LaunchSolenoids.h"

#include "../Robot.h"
#include "../Logging.h"

LaunchSolenoids::LaunchSolenoids(bool on)
  : Command("LaunchSolenoids"),
    m_on(on) {

  log_debug("LaunchSolenoids(%s)", on ? "true" : "false");
  Requires(Robot::shooter());
}

void LaunchSolenoids::Execute() {
  Robot::shooter()->LaunchSolenoids(m_on);
}

bool LaunchSolenoids::IsFinished() {
  return true;
}

void LaunchSolenoids::Initialize() {}
void LaunchSolenoids::End() {}
void LaunchSolenoids::Interrupted() {}
