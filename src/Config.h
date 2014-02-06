// Robot config and hardware ids

#ifndef _CONFIG_H_
#define _CONFIG_H_

namespace CONFIG {

  namespace HARDWARE {
    // Drive Motor ports
    const int drive_front_left = 3;
    const int drive_rear_left = 4;
    const int drive_front_right = 1;
    const int drive_rear_right = 2;

    const int drive_gyro = 1;

    // Special mech motors
    const int arm_wheel = 6;

    // Arm motors
    const int front_arm = 5;
    const int back_arm = 7;
  };

  namespace INPUT {
    // Drive Joystick port
    const int joystick_1 = 1;

    // ## Buttons
    const int gyro_toggle = 2;

    const int arm_wheel_forward = 1;
    const int arm_wheel_backward = 12;

    const int front_arm_up = 5;
    const int front_arm_down = 3;

    const int back_arm_up = 6;
    const int back_arm_down = 4;
  };

  // ## Preferences (Can be edited on the SmartDashboard)
  // The gyro scaling constant controls how strongly the gyro should correct.
  // Make it too high, and the robot will start over-correcting, begin
  // oscillating, and spin out of control.
  // Make it too low, and the robot will correct too slowly.
  float GyroScalingConstant();

  // Don't adjust the robot unless the gyro passes the threshold.
  float GyroThreshold();

  // After we turn the joystick, don't enable the gyro until X seconds have
  // passed.
  float GyroTimeout();

  // How fast the wheel on the arm should spin.
  // (+) pushes the ball out
  // (-) sucks the ball in
  float ArmWheelPower();

} // namespace CONFIG

#endif
