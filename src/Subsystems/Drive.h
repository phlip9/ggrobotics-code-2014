// Robot drivetrain subsystem

#ifndef _DRIVE_H
#define _DRIVE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Robot.h"

class Drive : public Subsystem {
 private:
  RobotDrive robot_drive;

 public:
  Drive();
  ~Drive();

  void InitDefaultCommand() override;

  void mecanum_drive(float x, float y, float rotation, float gyro_angle = 0.0);

}

#endif
