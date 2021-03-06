#include "AutonomousDrive.h"

#include "Timer.h"

#include "../Subsystems/Drive.h"
#include "../Logging.h"

AutonomousDrive::AutonomousDrive(Drive *drive, double seconds, float power)
  : Command("AutonomousDrive"),
    m_drive(drive),
    m_seconds(seconds),
    m_power(power),
    m_timer() {

  log_info("AutonomousDrive()");
  Requires(drive);
}

AutonomousDrive::~AutonomousDrive() {}

void AutonomousDrive::Initialize() {
  log_info("Initialize()");
  m_timer.Start();
}

void AutonomousDrive::Execute() {
  log_info("Timer: %.2f", m_timer.Get());
  // drive at half speed
  m_drive->drive(0, -m_power);
}

bool AutonomousDrive::IsFinished() {
  bool finished = m_timer.HasPeriodPassed(m_seconds);
  log_info("IsFinished() : %s", finished ? "true" : "false");
  return finished;
}

void AutonomousDrive::End() {
  log_info("End()");
  m_timer.Stop();
  m_timer.Reset();
}

void AutonomousDrive::Interrupted() {
  log_info("Interrupted()");
  m_timer.Stop();
  m_timer.Reset();
}

