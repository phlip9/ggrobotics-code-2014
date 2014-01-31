// Robot drive subsystem

#ifndef _SUBSYSTEMS_FRONT_ARM_H_
#define _SUBSYSTEMS_FRONT_ARM_H_

#include "Commands/Subsystem.h"

enum class Direction {UP, DOWN};

class FrontArm : public Subsystem {

 public:
  FrontArm();
  ~FrontArm();

  void move(Direction direction);

};

#endif
