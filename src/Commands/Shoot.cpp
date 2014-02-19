#include "Shoot.h"

#include "Commands/WaitCommand.h"

#include "LaunchSolenoids.h"
#include "../Logging.h"

Shoot::Shoot()
  : CommandGroup("Shoot") {

  log_debug("Shoot()");

  AddSequential(new LaunchSolenoids(true));
  AddSequential(new WaitCommand(1.0f));
  AddSequential(new LaunchSolenoids(false));

  SetInterruptible(false);
}
