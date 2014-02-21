#ifndef _COMMANDS_AUTONOMOUS_DRIVE_H_
#define _COMMANDS_AUTONOMOUS_DRIVE_H_

#include "Commands/Command.h"
#include "Timer.h"

class AutonomousDrive : public Command {
 public:
  AutonomousDrive(double seconds, float power);
  ~AutonomousDrive() override;

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  double m_seconds;
  float m_power;
  Timer m_timer;
};

#endif

