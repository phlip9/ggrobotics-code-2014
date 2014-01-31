#ifndef _COMMANDS_FRONT_ARM_MOVE_H_
#define _COMMANDS_FRONT_ARM_MOVE_H_

#include "Commands/Command.h"

#include "../Subsystems/FrontArm.h"

class FrontArmMove : public Command {
  public:
   explicit FrontArmMove(Direction direction);

   virtual void Initialize() override;
   virtual void Execute() override;
   virtual bool IsFinished() override;
   virtual void End() override;
   virtual void Interrupted() override;

  private:
   Direction m_direction;

};

#endif

