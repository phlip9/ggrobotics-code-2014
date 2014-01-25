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

  //void mecanum_drive(Joystick &drive_stick);
  void mecanum_drive(float x, float y, float turn = 0.0);

  void autonomous_drive(float x, float y, float twist);

  void toggle_gyro();

 private:
  RobotDrive robot_drive;
  bool gyro_enabled;

};

// Clamp a value between min and max
float clamp(float in, float min, float max);

// Threshold a value if it's between thresh_max and thresh_min
float deadband(float in, float min, float max, float out = 0.0);

#endif
