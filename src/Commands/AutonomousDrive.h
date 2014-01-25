#ifndef _COMMANDS_AUTONOMOUS_DRIVE_H_
#define _COMMANDS_AUTONOMOUS_DRIVE_H_

#include "Commands/Command.h"

class AutonomousDrive : public Command {
  public:
   AutonomousDrive();

   virtual void Initialize() override;
   virtual void Execute() override;
   virtual bool IsFinished() override;
   virtual void End() override;
   virtual void Interrupted() override;

};

#endif
    
