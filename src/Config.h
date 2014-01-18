// Robot config and hardware ids

#ifndef _CONFIG_H_
#define _CONFIG_H_

namespace CONFIG {

  // Motor channels
  int MotorFrontLeftDrive();
  int MotorRearLeftDrive();
  int MotorFrontRightDrive();
  int MotorRearRightDrive();

  int GyroChannel();

  // The gyro scaling constant controls how strongly the gyro should correct.
  // Make it too high, and the robot will start over-correcting, begin
  // oscillating, and spin out of control.
  // Make it too low, and the robot will correct too slowly.
  float GyroScalingConstant();

  // Drive Joystick port
  int JoystickDrive();

} // namespace CONFIG

#endif
