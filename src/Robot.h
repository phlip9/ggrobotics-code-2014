/*
 * Singleton Robot Class. Logically, there should be one and *only one* Robot
 * instance.
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
  static const Robot& GetInstance();

  void RobotInit() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void TestPeriodic() override;

 private:
  Robot();
  ~Robot() override;

  Robot(const Robot&); // Leave this unimplemented.
  void operator=(const Robot&); // This one too.

  // Maps hardware modules to software objects.
  HardwareMap hardware_map;

  // Operator Interface
  OI oi;

  // Subsystems
  Drive drive;
  Hook hook;

  LiveWindow *live_window;

  Command autonomous_command;
  Command teleop_command;

}

// START_ROBOT_CLASS(Robot);

// Override the START_ROBOT_CLASS macro and instead return a reference to the
// singleton instance.
RobotBase *FRC_userClassFactory() {
  return &GetInstance();
}

// Set the entry point to the program (a function pointer to the above method)
extern "C" {
  INT32 FRC_UserProgram_StartupLibraryInit() {
    RobotBase::startRobotTask((FUNCPTR) FRC_userClassFactory);
    return 0;
  }
}

#endif
