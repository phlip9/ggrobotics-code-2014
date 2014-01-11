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
  // Returns the Robot singleton instance
  static Robot& instance() { return (Robot&) RobotBase::getInstance(); };
  //static Robot& instance() { static Robot robot; return robot; }

  virtual void RobotInit() override;

  virtual void DisabledInit() override;
  virtual void DisabledPeriodic() override;

  virtual void AutonomousInit() override;
  virtual void AutonomousPeriodic() override;

  virtual void TeleopInit() override;
  virtual void TeleopPeriodic() override;

  virtual void TestInit() override;
  virtual void TestPeriodic() override;

  // Maps hardware modules to software objects.
  HardwareMap hardware_map;

  // Operator Interface
  OI oi;

  // Drivetrain subsystem
  Drive drive;

 private:
  // Don't want anyone instanciating this
  Robot();

  // Don't want anyone deleting this either
  ~Robot() override;

  // Allow construction of the singleton by the WPILib Framework
  friend RobotBase* FRC_userClassFactory();

  DriverStationLCD *ds_lcd;

  Command *autonomous_command;
  Command *teleop_command;

};

#endif
