/*
 * This class holds the hardware map, operator interface, and robot subsystems.
 * It also manages the different robot state logic, e.g. autonomous vs teleop vs
 * test mode.
 */

#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "RobotBase.h"
#include "IterativeRobot.h"
#include "Commands/Command.h"

#include "HardwareMap.h"
#include "OI.h"
#include "Subsystems/Drive.h"

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

  // Maps hardware modules to software objects.
  HardwareMap hardware_map;

  // Operator Interface
  OI oi;

  // Drivetrain subsystem
  Drive drive;

 private:
  Robot();

  Command autonomous_command;
  Command teleop_command;

};

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
