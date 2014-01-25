/*
 * Robot impementation. Controls teleop and autonomous periods. Holds all the
 * different robot subsystems.
 */

#include "Robot.h"

#include "Commands/Scheduler.h"
#include "LiveWindow/LiveWindow.h"
#include "DriverStationLCD.h"
#include "Commands/PrintCommand.h"
#include "Preferences.h"
#include "SmartDashboard/SmartDashboard.h"
#include "SmartDashboard/SendableChooser.h"

#include "Commands/AutonomousDrive.h"
#include "HardwareMap.h"
#include "OI.h"
#include "Subsystems/Drive.h"
#include "Logging.h"

Robot::Robot() {
  log_info("Robot()");
}

Robot::~Robot() {
  log_info("~Robot()");

  delete m_hardware_map;
  delete m_oi;
  delete m_drive;

  delete m_autonomous_command;
  delete m_teleop_command;
  delete m_autonomous_chooser;
}

void Robot::RobotInit() {
  log_info("-> RobotInit()");

  GetWatchdog().SetEnabled(false);

  m_hardware_map = new HardwareMap();
  m_oi = new OI();

  m_drive = new Drive();

  // Init the things
  hardware_map()->init();
  oi()->init();

  m_autonomous_chooser = new SendableChooser();
  m_autonomous_chooser->AddDefault("Do Nothing", new PrintCommand("AutonomousCommand"));

  // Add the autonomous chooser to the SmartDashboard
  SmartDashboard::PutData("Autonomous modes:", m_autonomous_chooser);

  log_info("<- RobotInit()");
}

void Robot::DisabledInit() {
  log_info("DisabledInit()");
  Preferences::GetInstance()->Save();
  log_info("----");
}

void Robot::DisabledPeriodic() {
  //log_info("DisabledPeriodic()");
}

void Robot::AutonomousInit() {
  //m_autonomous_command = (Command*) m_autonomous_chooser->GetSelected();
  m_autonomous_command = new AutonomousDrive();
  Scheduler::GetInstance()->AddCommand(m_autonomous_command);
  Scheduler::GetInstance()->Run();
  log_info("AutonomousInit()");
  //if (m_autonomous_command)
    //m_autonomous_command->Start();
}

void Robot::AutonomousPeriodic() {
  
  Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  log_info("TeleopInit()");
  //if (m_autonomous_command)
    //m_autonomous_command->Cancel();

  //if (m_teleop_command)
    //m_teleop_command->Start();
}

void Robot::TeleopPeriodic() {
  log_info("TeleopPeriodic()");
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
