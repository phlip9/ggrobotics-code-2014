#ifndef _COMMANDS_AUTONOMOUS_DRIVE_H_
#define _COMMANDS_AUTONOMOUS_DRIVE_H_

class Drive;

#include "Commands/Command.h"
#include "Timer.h"

class AutonomousDrive : public Command {
 public:
  AutonomousDrive(Drive *drive, double seconds, float power);
  ~AutonomousDrive() override;

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  Drive *m_drive;
  double m_seconds;
  float m_power;
  Timer m_timer;
};

#endif

