// Drives robot

#include "BackgroundDrive.h"

#include <stdio.h>

#include "../Robot.h"

BackgroundDrive::BackgroundDrive()
  : Command("BackgroundDrive") {

  Requires(Robot::drive);
}

void BackgroundDrive::Initialize() {

}

void BackgroundDrive::Execute() {
  //printf("BackgroundDrive.Execute() -> Driving...\n");
  Robot::drive->mecanum_drive(Robot::oi->drive_stick);
}

bool BackgroundDrive::IsFinished() {
  return false;
}

void BackgroundDrive::End() {

}

void BackgroundDrive::Interrupted() {

}
