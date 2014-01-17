// Robot config and hardware ids

#ifndef _CONFIG_H_
#define _CONFIG_H_

namespace CONFIG {

  int MotorFrontLeftDrive();
  int MotorRearLeftDrive();
  int MotorFrontRightDrive();
  int MotorRearRightDrive();

  float GyroScalingConstant();

  int JoystickDrive();

} // namespace CONFIG

#endif
