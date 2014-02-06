// Generic motor subsystem
// Used by front arm, back arm, and front arm wheels

#ifndef _SUBSYSTEMS_MOTOR_SUBSYSTEM_H_
#define _SUBSYSTEMS_MOTOR_SUBSYSTEM_H_

class SpeedController;

#include "Commands/Subsystem.h"

#include "../Robot.h"

class MotorSubsystem : public Subsystem {

 public:
  MotorSubsystem(const char* name, SpeedController* motor, float power_up = 1.0, float power_down = 1.0);
  virtual ~MotorSubsystem();

  virtual void move(Direction direction);
  virtual void move(float power);
  virtual void stop();

 private:
  const char* m_name;
  SpeedController* m_motor;
  float m_power_up;
  float m_power_down;

};

#endif
