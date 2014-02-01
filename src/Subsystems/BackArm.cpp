// Robot back arm subsystem

#include "BackArm.h"

#include "../Robot.h"
#include "../Logging.h"

BackArm::BackArm()
    : Subsystem("BackArm") {

  log_info("BackArm()");
}

BackArm::~BackArm() {
  log_info("~BackArm()");
}

void BackArm::move(Direction direction) {
  log_info("move(%s)", str_direction(direction));
  if (direction == Direction::UP)
    Robot::hardware_map()->back_arm_motor.Set(-0.40);
  else if (direction == Direction::DOWN)
    Robot::hardware_map()->back_arm_motor.Set(0.25);
  else
    log_error("Somehow direction is neither UP nor DOWN");
}

void BackArm::stop() {
  log_info("stop()");
  Robot::hardware_map()->back_arm_motor.Set(0.0);
}
