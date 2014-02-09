#include "ShooterToggle.h"

#include "../Robot.h"
#include "../Logging.h"

ShooterToggle::ShooterToggle()
  : Command("ShooterToggle") {

  log_debug("ShooterToggle()");
  Requires(Robot::shooter());
}

void ShooterToggle::Initialize() {
  log_debug("Initialize()");
}

void ShooterToggle::Execute() {
  Robot::shooter()->toggle();
}

bool ShooterToggle::IsFinished() {
  return true;
}

void ShooterToggle::End() {
  log_debug("End()");
}

void ShooterToggle::Interrupted() {
  log_debug("Interrupted()");
}
