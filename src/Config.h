// Robot config and hardware ids

#ifndef _CONFIG_H_
#define _CONFIG_H_

namespace CONFIG {

  int MotorFrontLeftDrive();
  int MotorRearLeftDrive();
  int MotorFrontRightDrive();
  int MotorRearRightDrive();

  int GyroChannel();
  float GyroScalingConstant();

  int JoystickDrive();

} // namespace CONFIG

#endif
