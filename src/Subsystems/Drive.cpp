// Robot drive subsystem

#include "Drive.h"

#include <stdio.h>

#include "SpeedController.h"

#include "../Robot.h"
#include "../Commands/BackgroundDrive.h"
#include "../Logging.h"

Drive::Drive()
    : Subsystem("Drive"),
      robot_drive((SpeedController*) Robot::hardware_map->front_left_motor,
                  (SpeedController*) Robot::hardware_map->rear_left_motor,
                  (SpeedController*) Robot::hardware_map->front_right_motor,
                  (SpeedController*) Robot::hardware_map->rear_right_motor) {

  robot_drive.SetExpiration(0.1);
}

Drive::~Drive() { }

void Drive::InitDefaultCommand() {
  SetDefaultCommand(new BackgroundDrive());
}

void Drive::mecanum_drive(Joystick &drive_stick) {
  float x, y, twist, throttle;
  x = drive_stick.GetX();
  y = drive_stick.GetY();

  // WARNING: WTF INCOMING
  // For some fuckign reason, the joystick has these swapped.
  // yeah... real straightforward
  twist = drive_stick.GetThrottle();
  throttle = drive_stick.GetTwist();

  log_debug("mecanum_drive() IN: x: %lf, y: %lf, twist: %lf, throttle: %lf",
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

  twist = clamp(twist, -1.0, 1.0);

  log_debug("mecanum_drive() OUT: x: %lf, y: %lf, twist: %lf, throttle: %lf",
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

