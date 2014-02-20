// Robot drive subsystem

#ifndef _SUBSYSTEMS_DRIVE_H_
#define _SUBSYSTEMS_DRIVE_H_

#include "Commands/Subsystem.h"

#include "RobotDrive.h"

class Drive : public Subsystem {
 public:
  Drive();
  ~Drive() override;

  void InitDefaultCommand() override;

  void mecanum_drive(float x, float y, float turn = 0.0);

 private:
  RobotDrive robot_drive;
};

#endif
