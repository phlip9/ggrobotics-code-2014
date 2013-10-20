/*
 * Robot impementation. Controls teleop and autonomous periods. Holds all the
 * different robot subsystems.
 */

#include "Robot.h"


Robot::Robot()
    : hardware_map(),
      drive(),
      hook(),
      oi(),
      autonomous_command(),
      teleop_command() {
  hardware_map.AddToLiveWindow();
  live_window = LiveWindow::GetInstance();
}

// Lazy evaluated singleton
const Robot& Robot::GetInstance() {
  // Instanciated on first GetInstance call.
  static const Robot instance;
  return instance;
}

void Robot::AutonomousInit() {
  autonomous_command.Start();
}

void Robot::AutonomousPeriodic() {
  Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  autonomous_command.Cancel();

  teleop_command.Start();
}

void Robot::TeleopPeriodic() {
  Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
  live_window->Run();
}
