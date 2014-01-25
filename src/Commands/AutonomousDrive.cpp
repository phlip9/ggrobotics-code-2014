#include "AutonomousDrive.h"

#include "Timer.h"

#include "../Robot.h"
#include "../Logging.h"

AutonomousDrive::AutonomousDrive(double seconds, float power)
  : Command("AutonomousDrive"),
    m_seconds(seconds),
    m_power(power),
    m_timer() {

  log_info("AutonomousDrive()");
  Requires(Robot::drive());
}

void AutonomousDrive::Initialize() {
  log_info("Initialize()");
  m_timer.Start();
}

void AutonomousDrive::Execute() {
  // drive at half speed
  Robot::drive()->mecanum_drive(0, 0.5);
}

bool AutonomousDrive::IsFinished() {
  return m_timer.HasPeriodPassed(m_seconds);
}

void AutonomousDrive::End() {
  log_info("End()");
}

void AutonomousDrive::Interrupted() {
  log_info("Interrupted()");
}

