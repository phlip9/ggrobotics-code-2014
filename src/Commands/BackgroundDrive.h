// This command runs by default in the Drive subsystem when no other commands
// are running in that subsystem.
// BackgroundDrive first polls the drive joystick and the drives the robot.

#ifndef _COMMANDS_BACKGROUND_DRIVE_H_
#define _COMMANDS_BACKGROUND_DRIVE_H_

#include "Commands/Command.h"

class BackgroundDrive : public Command {
  public:
   BackgroundDrive();
   ~BackgroundDrive();

   void Initialize() override;
   void Execute() override;
   bool IsFinished() override;
   void End() override;
   void Interrupted() override;

};

#endif
