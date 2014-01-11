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

// Allocate space for the static pointers

HardwareMap *Robot::hardware_map = 0;
OI *Robot::oi = 0;
Drive *Robot::drive = 0;

void Robot::RobotInit() {
  printf("RobotInit()\n");

  GetWatchdog().SetEnabled(false);

  hardware_map = new HardwareMap();
  oi = new OI();

  // Init the things
  hardware_map->init();
  oi->init();

  // Subsystems
  drive = new Drive();

  ds_lcd = DriverStationLCD::GetInstance();

  autonomous_command = new PrintCommand("AutonomousCommand");
  teleop_command = new PrintCommand("TeleopCommand");
}

void Robot::DisabledInit() {
  printf("DisabledInit()\n");
}

void Robot::DisabledPeriodic() {
  //printf("DisabledPeriodic()\n");
}

void Robot::AutonomousInit() {
  printf("AutonomousInit()\n");
  if (autonomous_command)
    autonomous_command->Start();
}

void Robot::AutonomousPeriodic() {
  printf("AutonomousPeriodic()\n");
  Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  //printf("TeleopInit()\n");
  if (autonomous_command)
    autonomous_command->Cancel();

  if (teleop_command)
    teleop_command->Start();
}

void Robot::TeleopPeriodic() {
  //printf("TeleopPeriodic()\n");
  Scheduler::GetInstance()->Run();
  ds_lcd->UpdateLCD();
}

void Robot::TestInit() {
  printf("TestInit()\n");
}

void Robot::TestPeriodic() {
  printf("TestPeriodic()\n");
  LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot);
