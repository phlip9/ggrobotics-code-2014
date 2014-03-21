#include "Robot.h"

#include "DriverStation.h"
#include "DriverStationLCD.h"
#include "Preferences.h"
#include "Commands/Scheduler.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

#include "Logging.h"
#include "Config.h"
#include "HardwareMap.h"
#include "OI.h"
#include "Subsystems/Drive.h"
#include "Subsystems/MotorSubsystem.h"
#include "Subsystems/ShooterSubsystem.h"
#include "Commands/AutonomousCommand.h"

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

  m_drive = new Drive(&m_hardware_map->front_left_motor,
                      &m_hardware_map->rear_left_motor,
                      &m_hardware_map->front_right_motor,
                      &m_hardware_map->rear_right_motor,
                      &m_oi->joystick_1);

  m_front_arm  = new MotorSubsystem("FrontArm",
                                    &m_hardware_map->front_arm_motor,
                                    CONFIG::FrontArmPowerUp(),
                                    CONFIG::FrontArmPowerDown());

  m_arm_wheels = new MotorSubsystem("ArmWheels",
                                    &m_hardware_map->wheel_motor,
                                    -CONFIG::ArmWheelPower(),
                                    CONFIG::ArmWheelPower());

  m_shooter = new ShooterSubsystem(&m_hardware_map->launch_solenoid_left,
                                   &m_hardware_map->launch_solenoid_right);

  m_autonomous_command = new AutonomousCommand(m_drive, m_arm_wheels, m_front_arm);

  // Call init after constructing everything else
  m_hardware_map->init();
  m_oi->init(m_arm_wheels, m_front_arm, m_shooter);

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
  LiveWindow::GetInstance()->SetEnabled(false);

  if (m_autonomous_command) {
    m_autonomous_command->Start();
  }

  //m_hardware_map->compressor.Start();
}

void Robot::AutonomousPeriodic() {
  Scheduler::GetInstance()->Run();
  DriverStationLCD::GetInstance()->UpdateLCD();
  UpdateSmartDashboard();
}

void Robot::TeleopInit() {
  log_debug("TeleopInit()");
  LiveWindow::GetInstance()->SetEnabled(false);

  if (m_autonomous_command) {
    m_autonomous_command->Cancel();
  }

  //m_hardware_map->compressor.Start();
}

void Robot::TeleopPeriodic() {
  Scheduler::GetInstance()->Run();
  DriverStationLCD::GetInstance()->UpdateLCD();
  UpdateSmartDashboard();
}

void Robot::TestInit() {
  log_info("TestInit()");
  LiveWindow::GetInstance()->SetEnabled(true);
}

void Robot::TestPeriodic() {
  LiveWindow::GetInstance()->Run();
}

void Robot::UpdateSmartDashboard() {
  float battery_voltage = DriverStation::GetInstance()->GetBatteryVoltage();
  SmartDashboard::PutNumber("Battery Voltage", battery_voltage);

  m_hardware_map->UpdateSmartDashboard();
  m_oi->UpdateSmartDashboard();
}

// !! DO NOT REMOVE !!
// Robot code entry point
// Actual pre-processor macro definition can be found in RobotBase.h
START_ROBOT_CLASS(Robot);
