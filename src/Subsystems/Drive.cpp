// Robot drive subsystem

#include "Drive.h"

#include <stdio.h>
#include <cmath>

#include "SpeedController.h"
#include "RobotDrive.h"

#include "../Robot.h"
#include "../Commands/BackgroundDrive.h"
#include "../Logging.h"
#include "../Config.h"

Drive::Drive()
    : Subsystem("Drive"),
      robot_drive(&Robot::hardware_map()->front_left_motor,
                  &Robot::hardware_map()->rear_left_motor,
                  &Robot::hardware_map()->front_right_motor,
                  &Robot::hardware_map()->rear_right_motor) {

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

void Drive::mecanum_drive(Joystick &drive_stick) {
  //Gyro &gyro = Robot::hardware_map()->gyro;
  //bool turning = false;
  float x, y, twist, throttle; //, gyroAngle;

  x = drive_stick.GetX();
  y = drive_stick.GetY();

  // WARNING: WTF INCOMING
  // For some fucking reason, the joystick has these swapped.
  // wow    much sense    many codes    wow
  twist = drive_stick.GetThrottle();
  throttle = drive_stick.GetTwist();

  //gyroAngle = gyro.GetAngle();

  log_info("IN: x: %lf, y: %lf, twist: %lf, throttle: %lf", //, gyroAngle: %lf",
           x, y, twist, throttle); //, gyroAngle);

  // Invert (because the throttle is backwards for no reason)
  // Add 1 to shift up (from [-1, 1] to [0, 2])
  // Divide by 2 to scale down (from [0, 2] to [0, 1])
  throttle = (-throttle + 1) / 2;

  // The joystick y axis is -0.15 at rest
  // so we ignore values below a threshold of 0.15
  y = threshold(y, -0.15, 0.15);

  twist = threshold(twist, -0.10, 0.10);
  //turning = twist == 0.0 && std::fabs(gyroAngle) > 1.0;

  x *= throttle;
  y *= throttle;
  twist *= throttle;

  //Twist is already thresholded between +- 0.1
  //Compare it to 0 to see if it met the threshold
  //if (turning) {
    //twist = gyroAngle * CONFIG::GyroScalingConstant();
  //} else {
    //If the Robot isn't turning, reset the gyro so it doesn't flip out
    //gyro.Reset();
  //}

  twist = clamp(twist, -1.0, 1.0);

  log_info("OUT: x: %lf, y: %lf, twist: %lf, throttle: %lf",
           x, y, twist, throttle);

  robot_drive.MecanumDrive_Cartesian(x, y, twist);
}

float clamp(float in, float min, float max) {
  if (in > max)
    return max;
  else if (in < min)
    return min;
  else
    return in;
}

float threshold(float in, float thresh_min, float thresh_max, float out) {
  if (in < thresh_max && in > thresh_min)
    return out;
  else
    return in;
}

