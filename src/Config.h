// Robot config and hardware ids

#ifndef _CONFIG_H_
#define _CONFIG_H_

namespace CONFIG {

  // ## Constants
  // Motor ports
  const int drive_motor_front_left = 3;
  const int drive_motor_rear_left = 4;
  const int drive_motor_front_right = 1;
  const int drive_motor_rear_right = 2;

  const int gyro_channel = 1;

  // Drive Joystick port
  const int drive_joystick = 1;

  const int button_gyro_toggle = 2;

  // ## Preferences (Can be edited on the SmartDashboard)
  // The gyro scaling constant controls how strongly the gyro should correct.
  // Make it too high, and the robot will start over-correcting, begin
  // oscillating, and spin out of control.
  // Make it too low, and the robot will correct too slowly.
  float GyroScalingConstant();

  // Don't adjust the robot unless the gyro passes the threshold.
  float GyroThreshold();

} // namespace CONFIG

#endif
