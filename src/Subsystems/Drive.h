// Robot drive subsystem
// Controls the driving of the robot
// Runs the BackgroundDrive command when no other commands are running.

#ifndef _SUBSYSTEMS_DRIVE_H_
#define _SUBSYSTEMS_DRIVE_H_

class Joystick;
class Talon;

#include "Commands/Subsystem.h"

#include "RobotDrive.h"

#include "../Commands/BackgroundDrive.h"

class Drive : public Subsystem {
 public:
  Drive(Talon *front_left, Talon *right_left, Talon *front_right,
        Talon *rear_right, Joystick *joystick);
  ~Drive() override;

  void InitDefaultCommand() override;

  void mecanum_drive(float x, float y, float turn = 0.0);

 private:
  RobotDrive robot_drive;
  BackgroundDrive m_default_command;
};

#endif
