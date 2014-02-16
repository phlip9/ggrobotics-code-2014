// Robot drive subsystem

#include "Drive.h"

#include <cmath>

#include "RobotDrive.h"
#include "Timer.h"

#include "../Robot.h"
#include "../Commands/BackgroundDrive.h"
#include "../Logging.h"
#include "../Config.h"

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
  SetDefaultCommand(new BackgroundDrive());
}

void Drive::mecanum_drive(float x, float y, float turn) {
  robot_drive.MecanumDrive_Cartesian(x, y, turn);
}


float clamp(float in, float min, float max) {
  if (in > max)
    return max;
  else if (in < min)
    return min;
  else
    return in;
}

float deadband(float in, float min, float max, float out) {
  if (in < max && in > min)
    return out;
  else
    return in;
}

