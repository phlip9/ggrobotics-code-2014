// Drives robot

#include "Commands/BackgroundDrive.h"

#include "Robot.h"
#include "Subsystems/Drive.h"

BackgroundDrive::BackgroundDrive()
  : Command("BackgroundDrive") {

  // TODO: Add Requires(Drive subsystem)
  // Requires(Robot::instance().drive)
}

BackgroundDrive::Initialize() {

}

BackgroundDrive::Execute() {

}

BackgroundDrive::IsFinished() {
  return false;
}

BackgroundDrive::End() {

}

BackgroundDrive::Interrupted() {

}
