// Holds all the constants and smart dashboard preferences in a centralized
// location. Should contain all the joystick ports, button numbers, motor
// channels, solenoid inputs, etc... Functions that wrap the Preferences
// object should go here too.  Preferences are constants that are displayed
// and can be changed in the SmartDashboard on the driver station.

#ifndef _CONFIG_H_
#define _CONFIG_H_

namespace CONFIG {

  namespace HARDWARE {
    // Drive Motor ports
    const int drive_front_left = 3;
    const int drive_rear_left = 4;
    const int drive_front_right = 1;
    const int drive_rear_right = 2;

    // Special mech motors
    const int arm_wheel = 6;

    // Arm motors
    const int front_arm = 5;

    // Launch Solenoids
    const int launch_solenoid_right = 2;
    const int launch_solenoid_left = 7;

    const int compressor_switch = 10;
    const int compressor_relay = 1;
  } // namespace HARDWARE

  namespace INPUT {
    // Drive Joystick port
    const int joystick_1 = 1;

    // Joystick 1 Buttons
    const int gyro_toggle = 2;

    const int arm_wheel_forward = 1;
    const int arm_wheel_backward = 12;

    const int front_arm_up = 3;
    const int front_arm_down = 5;

    const int shoot = 4;
  } // namespace INPUT

  // ## Preferences (Can be edited on the SmartDashboard)

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
