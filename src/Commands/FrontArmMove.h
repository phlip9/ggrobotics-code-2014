#ifndef _COMMANDS_FRONT_ARM_MOVE_H_
#define _COMMANDS_FRONT_ARM_MOVE_H_

#include "Commands/Command.h"

#include "../Robot.h"

class FrontArmMove : public Command {
 public:
  explicit FrontArmMove(Direction direction);
  ~FrontArmMove() override;

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  Direction m_direction;
};

#endif

