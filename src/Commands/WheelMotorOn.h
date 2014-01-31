#ifndef _COMMANDS_WHEEL_MOTOR_ON_H_
#define _COMMANDS_WHEEL_MOTOR_ON_H_

#include "Commands/Command.h"

class WheelMotorOn : public Command {
  public:
   explicit WheelMotorOn();

   virtual void Initialize() override;
   virtual void Execute() override;
   virtual bool IsFinished() override;
   virtual void End() override;
   virtual void Interrupted() override;

};

#endif

