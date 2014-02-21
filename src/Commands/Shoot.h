// This command toggles the shooter

#ifndef _COMMANDS_SHOOT_H_
#define _COMMANDS_SHOOT_H_

#include "Commands/CommandGroup.h"

class Shoot : public CommandGroup {
 public:
  Shoot();
  ~Shoot() override;
};

#endif
