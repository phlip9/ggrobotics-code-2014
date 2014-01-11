// Drives robot

#include "BackgroundDrive.h"

#include "../Robot.h"
#include "../Subsystems/Drive.h"

BackgroundDrive::BackgroundDrive()
  : Command("BackgroundDrive") {

  Requires(&Robot::instance().drive);
}

void BackgroundDrive::Initialize() {

}

void BackgroundDrive::Execute() {
  Robot* robot = &Robot::instance();
  robot->drive.mecanum_drive(robot->oi.drive_stick);
}

bool BackgroundDrive::IsFinished() {
  return false;
}

void BackgroundDrive::End() {

}

void BackgroundDrive::Interrupted() {

}
