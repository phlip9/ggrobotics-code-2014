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

void Drive::mecanum_drive(Joystick &drive_stick) {
  Gyro &gyro = Robot::hardware_map()->gyro;
  float x, y, twist, throttle, gyro_angle, gyro_scaler, gyro_threshold;

  x = drive_stick.GetX();
  y = drive_stick.GetY();

  // WARNING: WTF INCOMING
  // For some fucking reason, the joystick has these swapped.
  // wow    much sense    many codes    wow
  twist = drive_stick.GetThrottle();
  throttle = drive_stick.GetTwist();

  gyro_angle = gyro.GetAngle();
  gyro_scaler = CONFIG::GyroScalingConstant();
  gyro_threshold = CONFIG::GyroThreshold();

  log_info("IN: x: %lf, y: %lf, twist: %lf, throttle: %lf, gyro: %lf",
           x, y, twist, throttle, gyro_angle);

  // Add 1 to shift up (from [-1, 1] to [0, 2])
  // Divide by 2 to scale down (from [0, 2] to [0, 1])
  throttle = (-throttle + 1.0) / 2.0;

  x *= throttle;
  y *= throttle;
  twist *= throttle;

  // Use the Gyro if we're not twisting the joystick and the gyroAngle is
  // sufficiently large.
  if (gyro_enabled) {
    if (twist < 0.10 && twist > -0.10 && std::fabs(gyro_angle) > gyro_threshold) {
      twist = gyro_angle * gyro_scaler;
    } else {
      gyro.Reset();
    }
  }

  twist = clamp(twist, -1.0, 1.0);

  log_info("OUT: x: %lf, y: %lf, twist: %lf, throttle: %lf",
           x, y, twist, throttle);

  robot_drive.MecanumDrive_Cartesian(x, y, twist);
}

void Drive::toggle_gyro() {
  gyro_enabled = !gyro_enabled;
  Robot::hardware_map()->gyro.Reset();
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

