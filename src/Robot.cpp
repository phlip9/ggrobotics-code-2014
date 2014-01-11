/*
 * Robot impementation. Controls teleop and autonomous periods. Holds all the
 * different robot subsystems.
 */

#include "Robot.h"

#include <stdio.h>

#include "Commands/Scheduler.h"
#include "LiveWindow/LiveWindow.h"
#include "DriverStationLCD.h"
#include "Commands/PrintCommand.h"

Robot::Robot()
  : hardware_map(),
    oi(),
    drive(hardware_map),
    ds_lcd(DriverStationLCD::GetInstance()),
    autonomous_command(new PrintCommand("AutonomousCommand()")),
    teleop_command(new PrintCommand("TeleopCommand()")) {

}

Robot::~Robot() { }

void Robot::RobotInit() {
  printf("RobotInit()");
  hardware_map.init();
  oi.init();

  Robot::GetWatchdog().SetEnabled(false);
}

void Robot::DisabledInit() {
  printf("DisabledInit()");
}

void Robot::DisabledPeriodic() {
  printf("DisabledPeriodic()");
}

void Robot::AutonomousInit() {
  printf("AutonomousInit()");
  autonomous_command->Start();
}

void Robot::AutonomousPeriodic() {
  printf("AutonomousPeriodic()");
  Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  printf("TeleopInit()");
  autonomous_command->Cancel();

  teleop_command->Start();
}

void Robot::TeleopPeriodic() {
  printf("TeleopPeriodic()");
  Scheduler::GetInstance()->Run();
  ds_lcd->UpdateLCD();
}

void Robot::TestInit() {
  printf("TestInit()");
}

void Robot::TestPeriodic() {
  printf("TestPeriodic()");
  LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot);
