// Robot drive subsystem

#ifndef _SUBSYSTEMS_FRONT_ARM_H_
#define _SUBSYSTEMS_FRONT_ARM_H_

#include "Commands/Subsystem.h"

#include "../Robot.h"

class FrontArm : public Subsystem {

 public:
  FrontArm();
  ~FrontArm();

  void move(Direction direction);
  void stop();

};

#endif
