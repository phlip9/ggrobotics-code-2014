/*
 * Robot impementation. Controls teleop and autonomous periods. Holds all the
 * different robot subsystems.
 */

#include "Robot.h"

#include "DriverStationLCD.h"
#include "Preferences.h"
#include "Commands/Scheduler.h"
#include "Commands/PrintCommand.h"
#include "SmartDashboard/SmartDashboard.h"
#include "SmartDashboard/SendableChooser.h"
#include "LiveWindow/LiveWindow.h"

#include "Logging.h"
#include "Config.h"
#include "HardwareMap.h"
#include "OI.h"
#include "Subsystems/Drive.h"
#include "Subsystems/MotorSubsystem.h"
#include "Subsystems/ShooterSubsystem.h"
#include "Commands/AutonomousDrive.h"
#include "Commands/CompressorOn.h"

const char* str_direction(Direction direction) {
  return direction == Direction::UP ? "UP" : "DOWN";
}

Robot::Robot()
  : m_hardware_map(nullptr),
    m_oi(nullptr),
    m_drive(nullptr),
    m_front_arm(nullptr),
    m_arm_wheels(nullptr),
    m_shooter(nullptr),
    m_autonomous_command(nullptr),
    m_teleop_command(nullptr) {
  log_info("Robot()");
}

Robot::~Robot() {
  log_info("~Robot()");

  //delete m_autonomous_chooser;

  // delete in reverse construction order
  delete m_compressor_command;

  delete m_teleop_command;
  delete m_autonomous_command;

  delete m_shooter;

  delete m_arm_wheels;
  delete m_front_arm;

  delete m_drive;

  delete m_oi;
  delete m_hardware_map;
}

void Robot::RobotInit() {
  log_debug("-> RobotInit()");

  GetWatchdog().SetEnabled(false);

  m_hardware_map = new HardwareMap();
  m_oi = new OI();

  m_drive = new Drive();

  m_front_arm  = new MotorSubsystem("FrontArm", &hardware_map()->front_arm_motor,
                                    CONFIG::FrontArmPowerUp(), CONFIG::FrontArmPowerDown());
  m_arm_wheels = new MotorSubsystem("ArmWheels", &hardware_map()->wheel_motor,
                                    -CONFIG::ArmWheelPower(),
                                    CONFIG::ArmWheelPower());

  m_shooter = new ShooterSubsystem();

  m_autonomous_command = nullptr;
  m_teleop_command = nullptr;

  // Init the things
  hardware_map()->init();
  oi()->init();

  m_compressor_command = new CompressorOn();

  /*m_autonomous_chooser = new SendableChooser();
  m_autonomous_chooser->AddDefault("Do Nothing", new PrintCommand("AutonomousCommand"));
  m_autonomous_chooser->AddCommand("AutonomousDrive", new AutonomousDrive(5.0));

  // Add the autonomous chooser to the SmartDashboard
  SmartDashboard::PutData("Autonomous modes:", m_autonomous_chooser);*/

  // Drive forward for 5 seconds
  //m_autonomous_command = new AutonomousDrive(5.0, 0.5);

  //m_teleop_command = new PrintCommand("TeleopCommand()");

  log_debug("<- RobotInit()");
}

void Robot::DisabledInit() {
  log_debug("DisabledInit()");
  Preferences::GetInstance()->Save();

  if (m_autonomous_command) {
    m_autonomous_command->Cancel();
  }

  //if (m_teleop_command) {
    //m_teleop_command->Cancel();
  //}
}

void Robot::DisabledPeriodic() {
  //log_info("DisabledPeriodic()");
}

void Robot::AutonomousInit() {
  //m_autonomous_command = (Command*) m_autonomous_chooser->GetSelected();

  m_autonomous_command = new AutonomousDrive(0.5, 0.5);
  m_compressor_command = new CompressorOn();

  if(m_compressor_command) {
    m_compressor_command->Start();
  }
  if (m_autonomous_command) {
    m_autonomous_command->Start();
  }

  Scheduler::GetInstance()->Run();
  log_info("AutonomousInit()");
}

void Robot::AutonomousPeriodic() {
  Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  log_debug("TeleopInit()");

  if (m_autonomous_command) {
    m_autonomous_command->Cancel();
  }

  if (!m_compressor_command) {
    m_compressor_command = new CompressorOn();
    m_compressor_command->Start();
  } else {
    m_compressor_command->Start();
  }

  //if (m_teleop_command)
    //m_teleop_command->Start();
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
