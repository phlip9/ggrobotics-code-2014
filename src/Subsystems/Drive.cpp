// Robot drive subsystem

#include "Drive.h"

#include <stdio.h>
#include <cmath>

#include "SpeedController.h"
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
                  &Robot::hardware_map()->rear_right_motor),
      gyro_enabled(true) {

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
  //Gyro &gyro = Robot::hardware_map()->gyro;
  //float gyro_angle, gyro_scaler, gyro_threshold;

  /*gyro_angle = gyro.GetAngle();
  gyro_scaler = CONFIG::GyroScalingConstant();
  gyro_threshold = CONFIG::GyroThreshold();*/

  // Use the Gyro if we're not twisting the joystick and the gyroAngle is
  // sufficiently large.
  /*if (gyro_enabled) {
    if (twist < 0.05 && twist > -0.05 && std::fabs(gyro_angle) > gyro_threshold) {
      twist = gyro_angle * gyro_scaler;
    } else {
      gyro.Reset();
    }
  }*/

  twist = clamp(twist, -1.0, 1.0);

  log_info("OUT: x: %lf, y: %lf, twist: %lf, throttle: %lf",
           x, y, twist, throttle);

  robot_drive.MecanumDrive_Cartesian(x, y, twist);
}

void Drive::autonomous_drive(float x, float y, float twist) {
  x = clamp(x, -1, 1);
  y = clamp(y, -1, 1);
  twist = clamp (twist, -1, 1);
  robot_drive.MecanumDrive_Cartesian(x, y, twist);
}




void Drive::toggle_gyro() {
  //gyro_enabled = !gyro_enabled;
  //Robot::hardware_map()->gyro.Reset();
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

