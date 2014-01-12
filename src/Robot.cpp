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
#include "Preferences.h"
#include "SmartDashboard/SmartDashboard.h"
#include "SmartDashboard/SendableChooser.h"

#include "HardwareMap.h"
#include "OI.h"
#include "Subsystems/Drive.h"
#include "Logging.h"

// Allocate space for the static pointers

HardwareMap *Robot::hardware_map = 0;
OI *Robot::oi = 0;
Drive *Robot::drive = 0;

void Robot::RobotInit() {
  log_info("RobotInit()");

  GetWatchdog().SetEnabled(false);

  hardware_map = new HardwareMap();
  oi = new OI();

  // Init the things
  hardware_map->init();
  oi->init();

  // Subsystems
  drive = new Drive();

  ds_lcd = DriverStationLCD::GetInstance();

  autonomous_chooser = new SendableChooser();
  autonomous_chooser->AddDefault("Do Nothing", new PrintCommand("AutonomousCommand"));
}

void Robot::DisabledInit() {
  log_info("DisabledInit()");
  Preferences::GetInstance()->Save();
}

void Robot::DisabledPeriodic() {
  log_info("DisabledPeriodic()");
}

void Robot::AutonomousInit() {
  autonomous_command = (Command*) autonomous_chooser->GetSelected();

  log_info("AutonomousInit()");
  if (autonomous_command)
    autonomous_command->Start();
}

void Robot::AutonomousPeriodic() {
  log_info("AutonomousPeriodic()");
  Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  log_info("TeleopInit()");
  if (autonomous_command)
    autonomous_command->Cancel();

  if (teleop_command)
    teleop_command->Start();
}

void Robot::TeleopPeriodic() {
  log_info("TeleopPeriodic()");
  Scheduler::GetInstance()->Run();
  ds_lcd->UpdateLCD();
}

void Robot::TestInit() {
  log_info("TestInit()");
}

void Robot::TestPeriodic() {
  log_info("TestPeriodic()");
  LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot);
