#include "BackgroundDrive.h"

#include "Joystick.h"

#include "../Subsystems/Drive.h"
#include "../Logging.h"

BackgroundDrive::BackgroundDrive(Drive *drive, Joystick *joystick)
  : Command("BackgroundDrive"),
    m_drive(drive),
    m_joystick(joystick) {

  log_info("BackgroundDrive()");
  Requires(drive);
}

BackgroundDrive::~BackgroundDrive() {}

void BackgroundDrive::Initialize() {
  log_info("Initialize()");
}

void BackgroundDrive::Execute() {
  float x, y, turn, throttle;

  x = m_joystick->GetX();
  y = m_joystick->GetY();

  // WARNING: WTF INCOMING
  // For some fucking reason, the joystick has these swapped.
  // wow    much sense    many codes    wow
  turn = m_joystick->GetThrottle();
  throttle = m_joystick->GetTwist();

  //log_info("DRIVE_STICK: x: %.3f, y: %.3f, turn: %.3f, throttle: %.3f",
           //x, y, turn, throttle);

  // Add 1 to shift up (from [-1, 1] to [0, 2])
  // Divide by 2 to scale down (from [0, 2] to [0, 1])
  throttle = (-throttle + 1.0) / 2.0;

  // The X axis seems to be reversed;
  x = -x;

  x *= throttle;
  y *= throttle;
  turn *= throttle;

  m_drive->mecanum_drive(x, y, turn);
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
