// Drives robot

#include "BackgroundDrive.h"

#include "../Robot.h"
#include "../Subsystems/Drive.h"

BackgroundDrive::BackgroundDrive()
  : Command("BackgroundDrive") {

  Requires(Robot::drive);
}

void BackgroundDrive::Initialize() {

}

void BackgroundDrive::Execute() {
  Robot::drive->mecanum_drive(Robot::oi->drive_stick);
}

bool BackgroundDrive::IsFinished() {
  return false;
}

void BackgroundDrive::End() {

}

void BackgroundDrive::Interrupted() {

}
