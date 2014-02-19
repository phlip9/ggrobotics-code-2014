// This subsystem controls the catapult thing that shoots the ball.

#ifndef _SUBSYSTEMS_SHOOTER_SUBSYSTEM_H_
#define _SUBSYSTEMS_SHOOTER_SUBSYSTEM_H_

#include "Commands/Subsystem.h"

class ShooterSubsystem : public Subsystem {
 public:
  explicit ShooterSubsystem();
  virtual ~ShooterSubsystem();

  void LaunchSolenoids(bool on);
};

#endif
