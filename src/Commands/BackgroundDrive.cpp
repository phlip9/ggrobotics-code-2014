// Drives robot

#include "Commands/BackgroundDrive.h"

#include "Robot.h"
#include "Subsystems/Drive.h"

BackgroundDrive::BackgroundDrive()
  : Command("BackgroundDrive") {

  Requires(&Robot::instance().drive);
}

BackgroundDrive::Initialize() {

}

BackgroundDrive::Execute() {
  Robot* robot = &Robot::instance();
  robot->drive.mecanum_drive(robot->oi.drive_stick);
}

BackgroundDrive::IsFinished() {
  return false;
}

BackgroundDrive::End() {

}

BackgroundDrive::Interrupted() {

}
