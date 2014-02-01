#ifndef _COMMANDS_BACK_ARM_MOVE_H_
#define _COMMANDS_BACK_ARM_MOVE_H_

#include "Commands/Command.h"

#include "../Robot.h"

class BackArmMove : public Command {
  public:
   explicit BackArmMove(Direction direction);

   virtual void Initialize() override;
   virtual void Execute() override;
   virtual bool IsFinished() override;
   virtual void End() override;
   virtual void Interrupted() override;

  private:
   Direction m_direction;

};

#endif


