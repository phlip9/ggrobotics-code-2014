#include "Shoot.h"

#include "Commands/WaitCommand.h"

#include "../Subsystems/ShooterSubsystem.h"
#include "LaunchSolenoids.h"
#include "../Logging.h"

Shoot::Shoot(ShooterSubsystem *shooter)
  : CommandGroup("Shoot") {

  log_debug("Shoot()");

  // Shoot the ball
  AddSequential(new LaunchSolenoids(shooter, true));
  AddSequential(new WaitCommand(1.0));

  // Retract the shooter after 1 second
  AddSequential(new LaunchSolenoids(shooter, false));

  // We don't want to get interrupted and have the shooter get stuck.
  SetInterruptible(false);
}

Shoot::~Shoot() {}
