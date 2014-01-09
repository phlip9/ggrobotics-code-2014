/*
 * This class holds the hardware map, operator interface, and robot subsystems.
 * It also manages the different robot state logic, e.g. autonomous vs teleop vs
 * test mode.
 */

#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"

#include "OI.h"
#include "HardwareMap.h"

#include "Subsystems/Drive.h"
#include "Subsystems/Hook.h"

class Robot : public IterativeRobot {

 public:
  void RobotInit() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void TestPeriodic() override;

  Subsystem* RegisterSubsystem(std::string, Subsystem*);
  Subsystem* GetSubsystem(std::string);
  void RemoveSubsystem(std::string);

 private:
  Robot();
  ~Robot() override;

  Robot(const Robot&); // Leave this unimplemented.
  void operator=(const Robot&); // This one too.

  // Maps hardware modules to software objects.
  HardwareMap hardware_map;

  // Operator Interface
  OI oi;

  // Subsystem map
  std::unordered_map<std::string, Subsystem*> subsystems;

  Command autonomous_command;
  Command teleop_command;

}

START_ROBOT_CLASS(Robot);

#endif
