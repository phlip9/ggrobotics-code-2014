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
  oi.Init();
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
  LiveWindow::GetInstance()->Run();
}

Subsystem* RegisterSubsystem(std::string name, Subsystem* subsystem) {
  // Erase the current registered subsystem if it exists.
  if (subsystems.find(name) == subsystems.end) {
    RemoveSubsystem(name);
  }
  subsystems[name] = subsystem;
}

Subsystem* GetSubsystem(std::string name) {
  return subsystems.at(name);
}

void RemoveSubsystem(std::string name) {
  // Can't tell if I need to delete here...
  subsystems.erase(name);
}
