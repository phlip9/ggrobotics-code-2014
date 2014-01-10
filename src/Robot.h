/*
 * This class holds the hardware map, operator interface, and robot subsystems.
 * It also manages the different robot state logic, e.g. autonomous vs teleop vs
 * test mode.
 */

#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"

#include "HardwareMap.h"
#include "OI.h"

class Robot : public IterativeRobot {

 public:
  void RobotInit() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void TestPeriodic() override;

 private:
  Command *autonomous_command;
  Command *teleop_command;

  // Maps hardware modules to software objects.
  static HardwareMap *hardware_map;

  // Operator Interface
  static OI *oi;

}

START_ROBOT_CLASS(Robot);

#endif
