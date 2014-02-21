// Generic motor subsystem
// Used by front arm and front arm wheels

#include "MotorSubsystem.h"

#include "Commands/Subsystem.h"
#include "SpeedController.h"

#include "../Robot.h"
#include "../Logging.h"

MotorSubsystem::MotorSubsystem(const char* name, SpeedController* motor, float power_up, float power_down)
  : Subsystem(name),
    m_name(name),
    m_motor(motor),
    m_power_up(power_up),
    m_power_down(power_down) {

  log_debug("MotorSubsystem(name=%s, power_up=%.3f, power_down=%.3f)", name, power_up, power_down);
}

MotorSubsystem::~MotorSubsystem() {
  log_debug("~MotorSubsystem() [%s]", m_name);
}

void MotorSubsystem::move(float power) {
  m_motor->Set(power);
}

void MotorSubsystem::move(Direction direction) {
  if (direction == Direction::UP) {
    move(m_power_up);
  } else if (direction == Direction::DOWN) {
    move(m_power_down);
  } else {
    log_error("Somehow direction is neither UP nor DOWN");
    stop();
  }
}

void MotorSubsystem::stop() {
  move(0.0);
}
