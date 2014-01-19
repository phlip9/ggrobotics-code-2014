// This command gets run when the toggle button is released.
// When run, the command toggles whether or not the gyro is running.

#ifndef _COMMANDS_GYRO_TOGGLE_DRIVE_H_
#define _COMMANDS_GYRO_TOGGLE_DRIVE_H_

#include "Commands/Command.h"

class GyroToggle : public Command {
  public:
   GyroToggle();

   virtual void Initialize() override;
   virtual void Execute() override;
   virtual bool IsFinished() override;
   virtual void End() override;
   virtual void Interrupted() override;

};

#endif
