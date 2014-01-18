// Drives robot

#include "BackgroundDrive.h"

#include <stdio.h>

#include "../Robot.h"
#include "../Logging.h"

BackgroundDrive::BackgroundDrive()
  : Command("BackgroundDrive") {

  log_info("BackgroundDrive()");
  Requires(Robot::drive());
}

void BackgroundDrive::Initialize() {
  log_info("Initialize()");
}

void BackgroundDrive::Execute() {
  Joystick &drive_stick = Robot::oi()->drive_stick;
  Robot::drive()->mecanum_drive(drive_stick);
}

bool BackgroundDrive::IsFinished() {
  return false;
}

void BackgroundDrive::End() {
  log_info("End()");
}

void BackgroundDrive::Interrupted() {
  log_info("Interrupted()");
}
