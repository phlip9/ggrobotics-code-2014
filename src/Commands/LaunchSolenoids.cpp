#include "LaunchSolenoids.h"

#include "../Robot.h"
#include "../Logging.h"

LaunchSolenoids::LaunchSolenoids(bool open)
  : Command("LaunchSolenoids"),
    m_open(open) {

  log_debug("LaunchSolenoids(%s)", open ? "open" : "close");
  Requires(Robot::shooter());
}

LaunchSolenoids::~LaunchSolenoids() {}

void LaunchSolenoids::Execute() {
  Robot::shooter()->ToggleLaunchSolenoids(m_open);
}

bool LaunchSolenoids::IsFinished() {
  return true;
}

void LaunchSolenoids::Initialize() {}
void LaunchSolenoids::End() {}
void LaunchSolenoids::Interrupted() {}
