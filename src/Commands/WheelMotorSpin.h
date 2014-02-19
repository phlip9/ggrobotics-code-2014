#ifndef _COMMANDS_WHEEL_MOTOR_SPIN_H_
#define _COMMANDS_WHEEL_MOTOR_SPIN_H_

#include "Commands/Command.h"

#include "../Robot.h"

class WheelMotorSpin : public Command {
  public:
   explicit WheelMotorSpin(Direction direction);

   void Initialize() override;
   void Execute() override;
   bool IsFinished() override;
   void End() override;
   void Interrupted() override;

  private:
   Direction m_direction;

};

#endif

