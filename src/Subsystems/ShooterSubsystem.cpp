#include "ShooterSubsystem.h"

#include "Solenoid.h"

#include "../Logging.h"
#include "../Robot.h"

ShooterSubsystem::ShooterSubsystem(Solenoid *solenoid_left, Solenoid *solenoid_right)
  : Subsystem("ShooterSubsystem"),
    m_solenoid_left(solenoid_left),
    m_solenoid_right(solenoid_right) {

  log_debug("ShooterSubsystem()");
}

ShooterSubsystem::~ShooterSubsystem() {
  log_debug("~ShooterSubsystem()");
}

void ShooterSubsystem::ToggleLaunchSolenoids(bool open) {
  log_debug("ToggleLaunchSolenoids(%s)", open ? "open" : "close");
  m_solenoid_left->Set(open);
  m_solenoid_right->Set(open);
}
