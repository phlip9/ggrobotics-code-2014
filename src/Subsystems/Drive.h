// Robot drive subsystem

#ifndef _SUBSYSTEMS_DRIVE_H_
#define _SUBSYSTEMS_DRIVE_H_

#include "Commands/Subsystem.h"

#include "RobotDrive.h"
#include "Joystick.h"

class Drive : public Subsystem {

 public:
  Drive();
  ~Drive();

  void InitDefaultCommand() override;

  void mecanum_drive(Joystick &drive_stick);

 private:
  RobotDrive robot_drive;

};

// Clamp a value between min and max
float clamp(float in, float min, float max);

// Threshold a value if it's between thresh_max and thresh_min
float threshold(float in, float thresh_min, float thresh_max, float out = 0.0);

#endif
