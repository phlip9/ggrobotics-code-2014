// Robot drive subsystem

#include "Drive.h"

#include "RobotDrive.h"
#include "Joystick.h"
#include "Talon.h"

#include "../Commands/BackgroundDrive.h"
#include "../Robot.h"
#include "../Logging.h"

Drive::Drive(Talon *front_left, Talon *rear_left, Talon *front_right,
             Talon *rear_right, Joystick *joystick)
    : Subsystem("Drive"),
      robot_drive(front_left,
                  rear_left,
                  front_right,
                  rear_right),
      m_default_command(this, joystick) {

  robot_drive.SetExpiration(0.5);
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
  SetDefaultCommand(&m_default_command);
}

void Drive::drive(float x, float y, float turn) {
  // If we need to add a gyro, put the gyro code here.
  // You can look at commits before
  //  commit ef2d3eac7d40373c06639e7fc46fcb8eebb8e304
  //  Author: Matthew Gee <geem2014@gmail.com>
  //  Date:   Sun Feb 16 12:57:50 2014 -0800
  //
  //    Purged Gyro Code.  Hooray
  //
  // for semi-working gyro code.

  robot_drive.ArcadeDrive(y, turn);
}

