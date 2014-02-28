#include "LaunchSolenoids.h"

#include "../Subsystems/ShooterSubsystem.h"

#include "../Logging.h"

LaunchSolenoids::LaunchSolenoids(ShooterSubsystem *shooter, bool open)
  : Command("LaunchSolenoids"),
    m_shooter(shooter),
    m_open(open) {

  log_debug("LaunchSolenoids(%s)", open ? "open" : "close");
  Requires(shooter);
}

LaunchSolenoids::~LaunchSolenoids() {}

void LaunchSolenoids::Execute() {
  m_shooter->ToggleLaunchSolenoids(m_open);
}

bool LaunchSolenoids::IsFinished() {
  return true;
}

void LaunchSolenoids::Initialize() {}
void LaunchSolenoids::End() {}
void LaunchSolenoids::Interrupted() {}
