#ifndef _COMMANDS_WHEEL_MOTOR_SPIN_H_
#define _COMMANDS_WHEEL_MOTOR_SPIN_H_

#include "Commands/Command.h"

#include "../Robot.h"

class WheelMotorSpin : public Command {
  public:
   explicit WheelMotorSpin(Direction direction);

   virtual void Initialize() override;
   virtual void Execute() override;
   virtual bool IsFinished() override;
   virtual void End() override;
   virtual void Interrupted() override;

  private:
   Direction m_direction;

};

#endif

