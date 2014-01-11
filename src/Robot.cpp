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

Robot::Robot() {
  Robot::GetWatchdog().SetEnabled(false);
}

Robot::~Robot() { }

void Robot::RobotInit() {
  printf("RobotInit()");

  hardware_map = new HardwareMap();
  oi = new OI();

  // Init the things
  hardware_map->init();
  oi->init();

  // Subsystems
  drive = new Drive();

  ds_lcd = DriverStationLCD::GetInstance();

}

void Robot::DisabledInit() {
  printf("DisabledInit()");
}

void Robot::DisabledPeriodic() {
  printf("DisabledPeriodic()");
}

void Robot::AutonomousInit() {
  printf("AutonomousInit()");
  if (autonomous_command)
    autonomous_command->Start();
}

void Robot::AutonomousPeriodic() {
  printf("AutonomousPeriodic()");
  Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  printf("TeleopInit()");
  if (autonomous_command)
    autonomous_command->Cancel();

  if (teleop_command)
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
