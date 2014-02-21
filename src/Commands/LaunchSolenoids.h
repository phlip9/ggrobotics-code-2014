#ifndef _COMMANDS_LAUNCH_SOLENOIDS_H_
#define _COMMANDS_LAUNCH_SOLENOIDS_H_

#include "Commands/Command.h"

class LaunchSolenoids : public Command {
 public:
  explicit LaunchSolenoids(bool open);
  ~LaunchSolenoids() override;

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  bool m_open;
};

#endif
