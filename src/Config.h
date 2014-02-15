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

    // Solenoid channel
    const int shoot_solenoid = 1;

    const int compressor_switch = 2;
    const int compressor_relay = 3;
  };

  namespace INPUT {
    // Drive Joystick port
    const int joystick_1 = 1;

    // ## Buttons
    const int gyro_toggle = 2;

    const int arm_wheel_forward = 1;
    const int arm_wheel_backward = 12;

    const int front_arm_up = 3;
    const int front_arm_down = 5;

    const int shoot = 4;
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

  // How much power should be applied to the front arm motors when
  // going up and down.
  // (-) arm moves up (counter-clockwise)
  // (+) arm moves down (clockwise)
  float FrontArmPowerUp();
  float FrontArmPowerDown();

} // namespace CONFIG

#endif
