// Robot drive subsystem

#include "FrontArm.h"

#include "../Robot.h"
#include "../Logging.h"

FrontArm::FrontArm()
    : Subsystem("FrontArm") {

  log_info("Drive()");
}

FrontArm::~FrontArm() {
  log_info("~Drive()");
}

void FrontArm::move(Direction direction) {
  if (direction == Direction::UP)
    Robot::hardware_map()->front_arm_motor.Set(0.1);
  else if (direction == Direction::DOWN)
    Robot::hardware_map()->front_arm_motor.Set(-0.1);
  else
    log_error("Somehow direction is neither UP nor DOWN");
}
