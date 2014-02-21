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

void ShooterSubsystem::ToggleLaunchSolenoids(bool open) {
  log_debug("ToggleLaunchSolenoids(%s)", open ? "open" : "close");
  Robot::hardware_map()->launch_solenoid_right.Set(open);
  Robot::hardware_map()->launch_solenoid_left.Set(open);
}
