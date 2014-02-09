// This command gets run when the toggle button is released.
// When run, the command toggles whether or not the gyro is running.

#include "GyroToggle.h"

#include "../Robot.h"
#include "../Logging.h"

GyroToggle::GyroToggle()
  : Command("GyroToggle") {

  log_info("GyroToggle()");
}

void GyroToggle::Initialize() {
  log_info("Initialize()");
}

void GyroToggle::Execute() {
  Robot::drive()->toggle_gyro();
}

bool GyroToggle::IsFinished() {
  return true;
}

void GyroToggle::End() {
  log_info("End()");
}

void GyroToggle::Interrupted() {
  log_info("Interrupted()");
}
