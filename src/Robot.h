/*
 * This class holds the hardware map, operator interface, and robot subsystems.
 * It also manages the different robot state logic, e.g., autonomous vs teleop vs
 * test mode.
 */

#ifndef _ROBOT_H_
#define _ROBOT_H_

// forward declarations
class Command;
class SendableChooser;

class HardwareMap;
class OI;

class Drive;
class MotorSubsystem;
class ShooterSubsystem;

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

  // Robot-wide initialization. Runs when the robot starts up.
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
  // in RobotInit()
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

  // This command gets run when the robot enter teleop mode.
  Command* m_teleop_command;

  // Compressor Command
  Command* m_compressor_command;
  // The autonomous_chooser shows up on the SmartDashboard as a radio button
  // The user selects which command to run when the robot enters autonomous
  // mode.
  //SendableChooser* m_autonomous_chooser;

};

#endif
