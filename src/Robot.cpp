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

const char* str_direction(Direction direction) {
  return direction == Direction::UP ? "UP" : "DOWN";
}

// We initialize all the members to nullptrs but actually construct them in
// RobotInit.
Robot::Robot()
  : m_hardware_map(nullptr),
    m_oi(nullptr),
    m_drive(nullptr),
    m_front_arm(nullptr),
    m_arm_wheels(nullptr),
    m_shooter(nullptr),
    m_autonomous_command(nullptr) {

  log_info("Robot()");
}

Robot::~Robot() {
  log_info("~Robot()");

  //delete m_autonomous_chooser;

  // delete in reverse construction order

  delete m_autonomous_command;

  delete m_shooter;

  delete m_arm_wheels;
  delete m_front_arm;

  delete m_drive;

  delete m_oi;
  delete m_hardware_map;
}

void Robot::RobotInit() {
  log_debug("RobotInit()");

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

  // Drive forward for 0.7 seconds at half power.
  m_autonomous_command = new AutonomousDrive(0.7, 0.5);

  m_teleop_command = nullptr;

  // Call init after constructing everything else
  hardware_map()->init();
  oi()->init();

  // Add the scheduler and subsystems to the SmartDashboard
  // This lets us see the current running commands in each subsystem
  SmartDashboard::PutData("Current Scheduler Command:", Scheduler::GetInstance());

  SmartDashboard::PutData("Drive:", m_drive);
  SmartDashboard::PutData("Front Arm:", m_front_arm);
  SmartDashboard::PutData("Arm Wheels:", m_arm_wheels);
  SmartDashboard::PutData("Shooter:", m_shooter);
}

void Robot::DisabledInit() {
  log_debug("DisabledInit()");

  m_hardware_map->compressor.Stop();

  if (m_autonomous_command) {
    m_autonomous_command->Cancel();
  }
}

void Robot::DisabledPeriodic() { }

void Robot::AutonomousInit() {
  log_info("AutonomousInit()");

  if (m_autonomous_command) {
    m_autonomous_command->Start();
  }

  m_hardware_map->compressor.Start();
}

void Robot::AutonomousPeriodic() {
  Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  log_debug("TeleopInit()");

  if (m_autonomous_command) {
    m_autonomous_command->Cancel();
  }

  m_hardware_map->compressor.Start();
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

// !! DO NOT REMOVE !!
// Robot code entry point
// Actual pre-processor macro definition can be found in RobotBase.h
START_ROBOT_CLASS(Robot);
