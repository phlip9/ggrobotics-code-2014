// Robot drive subsystem

#ifndef _SUBSYSTEMS_DRIVE_H_
#define _SUBSYSTEMS_DRIVE_H_

#include "Commands/Subsystem.h"

#include "RobotDrive.h"

#include "HardwareMap.h"

class Drive : public Subsystem {

 public:
  explicit Drive(const HardwareMap& hardware_map);
  ~Drive();

  void InitDefaultCommand() override;

  void mecanum_drive(const Joystick& drive_stick);

 private:
  RobotDrive robot_drive;

}

#endif
