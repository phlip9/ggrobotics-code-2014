// Robot drive subsystem

#include "Drive.h"

#include <stdio.h>
#include <cmath>

#include "SpeedController.h"

#include "../Robot.h"
#include "../Commands/BackgroundDrive.h"
#include "../Logging.h"

Drive::Drive()
    : Subsystem("Drive"),
      robot_drive(Robot::hardware_map->front_left_motor,
                  Robot::hardware_map->rear_left_motor,
                  Robot::hardware_map->front_right_motor,
                  Robot::hardware_map->rear_right_motor) {

  robot_drive.SetExpiration(0.1);
}

Drive::~Drive() { }

void Drive::InitDefaultCommand() {
  SetDefaultCommand(new BackgroundDrive());
}

void Drive::mecanum_drive(Joystick &drive_stick) {
  Gyro &gyro = Robot::hardware_map->gyro;
  float x, y, twist, throttle, gyroAngle;

  x = drive_stick.GetX();
  y = drive_stick.GetY();

  // WARNING: WTF INCOMING
  // For some fuckign reason, the joystick has these swapped.
  // yeah... real straightforward
  twist = drive_stick.GetThrottle();
  throttle = drive_stick.GetTwist();

  log_info("mecanum_drive() IN: x: %lf, y: %lf, twist: %lf, throttle: %lf",
           x, y, twist, throttle);

  // Invert (because the throttle is backwards for no reason)
  // Add 1 to shift up (from [-1, 1] to [0, 2])
  // Divide by 2 to scale down (from [0, 2] to [0, 1])
  throttle = (-throttle + 1) / 2;

  // The joystick y axis is -0.15 at rest
  // so we ignore values below a threshold of 0.15
  y = threshold(y, -0.15, 0.15);

  // threshold the twist too
  twist = threshold(twist, -0.10, 0.10);

  x *= throttle;
  y *= throttle;
  twist *= throttle;

  //get the Gyro Angle
  gyroAngle = gyro.GetAngle();

  // Discard Gyro Angle if the Joystick isn't turned enough (default leaning)
  if (std::fabs(x) < 0.05 && std::fabs(y) < 0.05 && std::fabs(twist) < 0.05)
    gyro.Reset();

  //Twist is already thresholded between +- 0.1
  //Compare it to 0 to see if it met the threshold
  if (twist == 0.0) {
    //If it didn't get thresholded and the gyroAngle > +- 1 (how far the robot has turned)
    //Multiply by a constant to adjust how fast the robot attempts to turn
    //Larger number means quicker turning.  Too large and the Robot Oscillates
    if (gyroAngle > 1 || gyroAngle < -1)
      twist = gyroAngle * -0.0125;
  } else {

    //If the Robot isn't supposed to turn, reset the gyro so it doesn't flip out
    gyro.Reset();
  }

  twist = clamp(twist, -1.0, 1.0);

  log_info("mecanum_drive() OUT: x: %lf, y: %lf, twist: %lf, throttle: %lf",
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

