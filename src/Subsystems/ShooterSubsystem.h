// This subsystem controls the catapult thing that shoots the ball.

#ifndef _SUBSYSTEMS_SHOOTER_SUBSYSTEM_H_
#define _SUBSYSTEMS_SHOOTER_SUBSYSTEM_H_

class Solenoid;

#include "Commands/Subsystem.h"

class ShooterSubsystem : public Subsystem {
 public:
  ShooterSubsystem(Solenoid *solenoid_left, Solenoid *solenoid_right);
  ~ShooterSubsystem() override;

  void ToggleLaunchSolenoids(bool open);

 private:
  Solenoid *m_solenoid_left;
  Solenoid *m_solenoid_right;
};

#endif
