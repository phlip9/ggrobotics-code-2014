// Robot drivetrain subsystem

#ifndef _DRIVE_H
#define _DRIVE_H

#include "WPILib.h"

class Drive : public Subsystem {
 public:
  Drive();
  ~Drive();

 private:
  RobotDrive robotdrive;

  Jaguar front_left_motor;
  Jaguar front_right_motor;
  Jaguar rear_left_motor;
  Jaguar rear_right_motor;

}

#endif
