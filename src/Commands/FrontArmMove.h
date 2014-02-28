#ifndef _COMMANDS_FRONT_ARM_MOVE_H_
#define _COMMANDS_FRONT_ARM_MOVE_H_

class MotorSubsystem;

#include "Commands/Command.h"

#include "../Robot.h"

class FrontArmMove : public Command {
 public:
  FrontArmMove(MotorSubsystem *front_arm, Direction direction);
  ~FrontArmMove() override;

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  MotorSubsystem *m_front_arm;
  Direction m_direction;
};

#endif

