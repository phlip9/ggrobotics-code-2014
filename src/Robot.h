/*
 * The Robot class holds the hardware map, operator interface, and robot
 * subsystems; manages the different robot state logic, e.g.,
 * disabled, autonomous vs teleop vs test mode; and is the entry point of the
 * program.
 */

#ifndef _ROBOT_H_
#define _ROBOT_H_

// forward declarations
// (we use forward declarations for the pointer types we use in the class
// because it means less includes and therefore faster compile times).
class Command;
class SendableChooser;

class HardwareMap;
class OI;

class Drive;
class MotorSubsystem;
class ShooterSubsystem;

// Reverse dependency issue, so we declare this before the includes.
enum class Direction {UP, DOWN};

#include "RobotBase.h"
#include "IterativeRobot.h"

#include "HardwareMap.h"
#include "OI.h"

#include "Subsystems/Drive.h"
#include "Subsystems/MotorSubsystem.h"
#include "Subsystems/ShooterSubsystem.h"

const char* str_direction(Direction direction);

class Robot : public IterativeRobot {

 public:
  ~Robot() override;

  // Singleton accessor
  static Robot& instance() { return (Robot&) RobotBase::getInstance(); };

  // Robot state methods inherited from IterativeRobot
  // RobotInit() gets called after the robot boots and the code is loaded.
  // Each state Init method gets called once upon entering the given state and
  // then the Periodic functions get called every `IterativeRobot::GetPeriod()`
  // which is 50 Hz by default (50 cycles/second)

  void RobotInit() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  // Static accessors for easy accessing
  static HardwareMap* hardware_map() { return instance().m_hardware_map; };
  static OI* oi() { return instance().m_oi; };

  static Drive* drive() { return instance().m_drive; };

  static MotorSubsystem* front_arm() { return instance().m_front_arm; };
  static MotorSubsystem* arm_wheels() { return instance().m_arm_wheels; };

  static ShooterSubsystem* shooter() { return instance().m_shooter; };

 private:
  // Give WPILib access to the Robot constructor
  friend RobotBase* FRC_userClassFactory();

  // The constructor is private because Robot is a singleton.
  // Also, don't actually construct anything in here. The robot life cycle
  // is totally whacked; so, for now, do all of the constructing and initing
  // in RobotInit() (which means members should be pointers initialized
  // to nullptrs)
  Robot();

  // Maps hardware modules to software objects.
  HardwareMap* m_hardware_map;

  // Operator Interface: holds Joysticks, Buttons, and maps buttons to commands
  OI* m_oi;

  // Drivetrain subsystem: controls the driving of the robot.
  Drive* m_drive;

  // Front arm subsystem: Controls the front arm of the robot.
  MotorSubsystem* m_front_arm;

  // Arm wheels subsystem: Controls the wheels on the front arm that grab the
  // ball.
  MotorSubsystem* m_arm_wheels;

  // Shooter subsystem: controls the solenoid to shoot the ball.
  ShooterSubsystem* m_shooter;

  // This command gets run when the robot enters autonomous mode.
  Command* m_autonomous_command;
};

#endif
