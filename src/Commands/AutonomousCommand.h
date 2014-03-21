// Command for autonomous mode

#ifndef _COMMANDS_AUTONOMOUS_COMMAND_H_
#define _COMMANDS_AUTONOMOUS_COMMAND_H_

class Drive;
class MotorSubsystem;

#include "Commands/CommandGroup.h"

class AutonomousCommand : public CommandGroup {
 public:
  AutonomousCommand(Drive *drive,
                    MotorSubsystem *arm_wheels,
                    MotorSubsystem *front_arm);
  ~AutonomousCommand() override;

 private:
  CommandGroup *m_arm_n_wheels;
};

#endif
