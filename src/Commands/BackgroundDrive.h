// This command runs by default in the Drive subsystem when no other commands
// are running in that subsystem.
// BackgroundDrive first polls the drive joystick and the drives the robot.

#ifndef _COMMANDS_BACKGROUND_DRIVE_H_
#define _COMMANDS_BACKGROUND_DRIVE_H_

#include "Commands/Command.h"

class BackgroundDrive : public Command {
  public:
   BackgroundDrive();

   virtual void Initialize() override;
   virtual void Execute() override;
   virtual bool IsFinished() override;
   virtual void End() override;
   virtual void Interrupted() override;

};

#endif
