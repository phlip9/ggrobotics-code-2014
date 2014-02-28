// This command toggles the shooter

#ifndef _COMMANDS_SHOOT_H_
#define _COMMANDS_SHOOT_H_

class ShooterSubsystem;

#include "Commands/CommandGroup.h"

class Shoot : public CommandGroup {
 public:
  Shoot(ShooterSubsystem *shooter);
  ~Shoot() override;
};

#endif
