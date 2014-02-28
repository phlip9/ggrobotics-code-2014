#ifndef _COMMANDS_LAUNCH_SOLENOIDS_H_
#define _COMMANDS_LAUNCH_SOLENOIDS_H_

class ShooterSubsystem;

#include "Commands/Command.h"

class LaunchSolenoids : public Command {
 public:
  LaunchSolenoids(ShooterSubsystem *shooter, bool open);
  ~LaunchSolenoids() override;

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  ShooterSubsystem *m_shooter;
  bool m_open;
};

#endif
