#include "ShooterSubsystem.h"

#include "../Logging.h"
#include "../Robot.h"

ShooterSubsystem::ShooterSubsystem()
  : Subsystem("ShooterSubsystem") {

  log_debug("ShooterSubsystem()");
}

ShooterSubsystem::~ShooterSubsystem() {
  log_debug("~ShooterSubsystem()");
}

void ShooterSubsystem::LaunchSolenoids(bool on) {
  log_debug("LaunchSolenoids(%s)", on ? "true" : "false");
  Robot::hardware_map()->launch_solenoid_right.Set(on);
  Robot::hardware_map()->launch_solenoid_left.Set(on);
}
