/*
 * This class holds the hardware map, operator interface, and robot subsystems.
 * It also manages the different robot state logic, e.g. autonomous vs teleop vs
 * test mode.
 */

#ifndef _ROBOT_H_
#define _ROBOT_H_

class DriverStationLCD;

#include "WPILib.h"

#include "RobotBase.h"
#include "IterativeRobot.h"
#include "Commands/Command.h"

#include "HardwareMap.h"
#include "OI.h"
#include "Subsystems/Drive.h"

class Robot : public IterativeRobot {

 public:
  Robot();
  ~Robot() override;

  void RobotInit() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  // Maps hardware modules to software objects.
  static HardwareMap *hardware_map;

  // Operator Interface
  static OI *oi;

  // Drivetrain subsystem
  static Drive *drive;

 private:
  // Allow construction of the singleton by the WPILib Framework
  friend RobotBase* FRC_userClassFactory();

  DriverStationLCD *ds_lcd;

  Command *autonomous_command;
  Command *teleop_command;

};

#endif
