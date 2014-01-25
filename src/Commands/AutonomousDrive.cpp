include "AutonomousDrive.h"

#include <stdio.h>

#include "../Robot.h"
#include "../Logging.h"

AutonomousDrive::AutonomousDrive()
  : Command("AutonomousDrive") {

  log_info("AutonomousDrive");
  Requires(Robot::drive());
}

void BackgroundDrive::Initialize() {
  log_info("Initialize()");
}

void BackgroundDrive::Execute() {
  //I hope this only calls once  
  Robot::drive()->mecanum_drive(0, 0.5, 0);
}

bool BackgroundDrive::IsFinished() {
  return true;
}

void BackgroundDrive::End() {
  log_info("End()");
}

void BackgroundDrive::Interrupted() {
  log_info("Interrupted()");
}

