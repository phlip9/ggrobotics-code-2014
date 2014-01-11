// Robot drive subsystem

#ifndef _SUBSYSTEMS_DRIVE_H_
#define _SUBSYSTEMS_DRIVE_H_

#include "Commands/Subsystem.h"

#include "RobotDrive.h"
#include "Joystick.h"

#include "../HardwareMap.h"

class Drive : public Subsystem {

 public:
  Drive();
  ~Drive();

  void InitDefaultCommand() override;

  void mecanum_drive(Joystick &drive_stick);

 private:
  RobotDrive robot_drive;

};

#endif
