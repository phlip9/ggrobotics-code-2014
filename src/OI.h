/*
 * Holds the user input objects (Joysticks, JoystickButtons, and
 * DigitalInButtons) and maps user input to respective commands, e.g., when
 * user releases the button, launch the ball.
 */

#ifndef _OI_H_
#define _OI_H_

class MotorSubsystem;
class ShooterSubsystem;

#include "Joystick.h"
#include "Buttons/JoystickButton.h"

class OI {
 public:
  OI();
  ~OI();

  // Wires the buttons, joysticks, and SmartDashboard controls to their
  // respective commands.
  void init(MotorSubsystem *arm_wheel, MotorSubsystem *front_arm, ShooterSubsystem *shooter);

  // Puts the current joystick values on the SmartDashboard.
  void UpdateSmartDashboard();

  Joystick joystick_1;

  JoystickButton button_wheel_spin_forward;
  JoystickButton button_wheel_spin_backward;

  JoystickButton button_front_arm_up;
  JoystickButton button_front_arm_down;

  JoystickButton button_shoot;
};

#endif
