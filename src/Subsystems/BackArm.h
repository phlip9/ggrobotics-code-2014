// Robot front arm subsystem

#ifndef _SUBSYSTEMS_BACK_ARM_H_
#define _SUBSYSTEMS_BACK_ARM_H_

#include "Commands/Subsystem.h"

#include "../Robot.h"

class BackArm : public Subsystem {

 public:
  BackArm();
  ~BackArm();

  void move(Direction direction);
  void stop();

};

#endif
