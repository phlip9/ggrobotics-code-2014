#include "ShooterSubsystem.h"

#include "../Robot.h"

ShooterSubsystem::ShooterSubsystem()
  : Subsystem("ShooterSubsystem"),
    m_on(false) {

  log_debug("ShooterSubsystem()");
}

ShooterSubsystem::~ShooterSubsystem() {
  log_debug("~ShooterSubsystem()");
}

void ShooterSubsystem::toggle() {
  m_on = !m_on;
  log_debug("toggle() shooter_solenoid.Set(%s)", m_on ? "on" : "off");
  Robot::hardware_map()->shoot_solenoid.Set(m_on);
}
