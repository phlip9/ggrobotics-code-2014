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

Robot::Robot() :
  m_hardware_map(),
  m_oi(),
  m_drive(),
  m_autonomous_command(new PrintCommand("AutonomousCommand")),
  m_teleop_command(new PrintCommand("TeleopCommand")),
  m_autonomous_chooser() {

}

Robot::~Robot() {
  delete m_autonomous_command;
  delete m_teleop_command;
}

void Robot::RobotInit() {
  log_info("RobotInit()");

  GetWatchdog().SetEnabled(false);

  // Init the things
  m_hardware_map.init();
  m_oi.init();

  m_autonomous_chooser.AddDefault("Do Nothing", new PrintCommand("AutonomousCommand"));

  SmartDashboard::PutData("Autonomous modes:", &m_autonomous_chooser);
}

void Robot::DisabledInit() {
  log_info("DisabledInit()");
  Preferences::GetInstance()->Save();
}

void Robot::DisabledPeriodic() {

}

void Robot::AutonomousInit() {
  m_autonomous_command = (Command*) m_autonomous_chooser.GetSelected();

  log_info("AutonomousInit()");
  if (m_autonomous_command)
    m_autonomous_command->Start();
}

void Robot::AutonomousPeriodic() {
  Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  log_info("TeleopInit()");
  if (m_autonomous_command)
    m_autonomous_command->Cancel();

  if (m_teleop_command)
    m_teleop_command->Start();
}

void Robot::TeleopPeriodic() {
  Scheduler::GetInstance()->Run();
  DriverStationLCD::GetInstance()->UpdateLCD();
}

void Robot::TestInit() {
  log_info("TestInit()");
}

void Robot::TestPeriodic() {
  LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot);
