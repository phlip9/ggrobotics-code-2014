// Robot front arm subsystem

#include "FrontArm.h"

#include "../Robot.h"
#include "../Logging.h"

FrontArm::FrontArm()
    : Subsystem("FrontArm") {

  log_info("FrontArm()");
}

FrontArm::~FrontArm() {
  log_info("~FrontArm()");
}

void FrontArm::move(Direction direction) {
  log_info("move(%s)", str_direction(direction));
  if (direction == Direction::UP) {
    Robot::hardware_map()->front_arm_motor.Set(-0.40);
  } else if (direction == Direction::DOWN) {
    Robot::hardware_map()->front_arm_motor.Set(0.25);
  } else {
    log_error("Somehow direction is neither UP nor DOWN");
  }
}

void FrontArm::stop() {
  log_info("stop()");
  Robot::hardware_map()->front_arm_motor.Set(0.0);
}
