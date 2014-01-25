// Drives robot

#include "BackgroundDrive.h"

#include <stdio.h>

#include "../Robot.h"
#include "../Logging.h"

BackgroundDrive::BackgroundDrive()
  : Command("BackgroundDrive") {

  log_info("BackgroundDrive()");
  Requires(Robot::drive());
}

void BackgroundDrive::Initialize() {
  log_info("Initialize()");
}

void BackgroundDrive::Execute() {
  Joystick &drive_stick = Robot::oi()->drive_stick;
  float x, y, turn, throttle;

  x = drive_stick.GetX();
  y = drive_stick.GetY();

  // WARNING: WTF INCOMING
  // For some fucking reason, the joystick has these swapped.
  // wow    much sense    many codes    wow
  turn = drive_stick.GetThrottle();
  throttle = drive_stick.GetTwist();

  log_info("DRIVE_STICK: x: %lf, y: %lf, turn: %lf, throttle: %lf",
           x, y, turn, throttle);

  // Add 1 to shift up (from [-1, 1] to [0, 2])
  // Divide by 2 to scale down (from [0, 2] to [0, 1])
  throttle = (-throttle + 1.0) / 2.0;

  x *= throttle;
  y *= throttle;
  turn *= throttle;

  Robot::drive()->mecanum_drive(x, y, turn);
}

bool BackgroundDrive::IsFinished() {
  return false;
}

void BackgroundDrive::End() {
  log_info("End()");
}

void BackgroundDrive::Interrupted() {
  log_info("Interrupted()");
}
