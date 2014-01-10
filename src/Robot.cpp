/*
 * Robot impementation. Controls teleop and autonomous periods. Holds all the
 * different robot subsystems.
 */

#include "Robot.h"

void Robot::RobotInit() {
  hardware_map = new HardwareMap();
  oi = new OI();

  hardware_map.init();
  oi.init();
}

void Robot::AutonomousInit() {
  autonomous_command->Start();
}

void Robot::AutonomousPeriodic() {
  Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  autonomous_command->Cancel();

  teleop_command->Start();
}

void Robot::TeleopPeriodic() {
  Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
  LiveWindow::GetInstance()->Run();
}
