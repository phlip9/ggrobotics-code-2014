// This command toggles the shooter

#ifndef _COMMANDS_SHOOTER_TOGGLE_H_
#define _COMMANDS_SHOOTER_TOGGLE_H_

#include "Commands/Command.h"

class ShooterToggle : public Command {
 public:
  ShooterToggle();

  virtual void Initialize() override;
  virtual void Execute() override;
  virtual bool IsFinished() override;
  virtual void End() override;
  virtual void Interrupted() override;
};

#endif
