#ifndef _COMMANDS_MOTOR_MOVE_H_
#define _COMMANDS_MOTOR_MOVE_H_

class MotorSubsystem;

#include "Commands/Command.h"

#include "../Robot.h"

class MotorMove : public Command {
 public:
  MotorMove(const char* name, MotorSubsystem *subsystem, Direction direction);
  ~MotorMove() override;

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  const char* m_name;
  MotorSubsystem *m_subsystem;
  Direction m_direction;
};

#endif
