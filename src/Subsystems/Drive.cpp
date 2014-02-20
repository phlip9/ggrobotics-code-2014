// Robot drive subsystem

#include "Drive.h"

#include "RobotDrive.h"

#include "../Commands/BackgroundDrive.h"
#include "../Robot.h"
#include "../Logging.h"

Drive::Drive()
    : Subsystem("Drive"),
      robot_drive(&Robot::hardware_map()->front_left_motor,
                  &Robot::hardware_map()->rear_left_motor,
                  &Robot::hardware_map()->front_right_motor,
                  &Robot::hardware_map()->rear_right_motor){

  robot_drive.SetExpiration(0.1);
  robot_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
  robot_drive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);

  log_info("Drive()");
}

Drive::~Drive() {
  log_info("~Drive()");
}

void Drive::InitDefaultCommand() {
  log_info("InitDefaultCommand()");

  // BackgroundDrive (which takes input from the joystick and calls
  // mecanum_drive) should run whenever no other command is using this
  // subsystem.
  SetDefaultCommand(new BackgroundDrive());
}

void Drive::mecanum_drive(float x, float y, float turn) {
  // If we need to add a gyro, put the gyro code here.
  // You can look at commits before
  //  commit ef2d3eac7d40373c06639e7fc46fcb8eebb8e304
  //  Author: Matthew Gee <geem2014@gmail.com>
  //  Date:   Sun Feb 16 12:57:50 2014 -0800
  //
  //    Purged Gyro Code.  Hooray
  //
  // for semi-working gyro code.

  robot_drive.MecanumDrive_Cartesian(x, y, turn);
}

