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
  ~Robot() override;

  static Robot &instance() { static Robot instance; return instance; }

  void RobotInit() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

 private:
  Robot();

  Command autonomous_command;
  Command teleop_command;

  // Maps hardware modules to software objects.
  HardwareMap hardware_map;

  // Operator Interface
  OI oi;

}

RobotBase *FRC_userClassFactory() {
  return &Robot::instance();
}

extern "C" {
  INT32 FRC_UserProgram_StartupLibraryInit() {
    RobotBase::startRobotTask((FUNCPTR) FRC_userClassFactory);
    return 0;
  }
}

#endif
