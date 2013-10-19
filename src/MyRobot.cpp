#include "WPILib.h"

namespace {
  // turning rate for robot.  from 0 (no turning) -> 1 (crazy turning)
  const float TURNING_RATE = 0.75f;
} // unnamed namespace, holds constants

class Robot : public SimpleRobot {
  RobotDrive myRobot;

  Joystick stick;
  Joystick stick2;

  JoystickButton solenoid_up_button;
  JoystickButton solenoid_down_button;

  JoystickButton turn_left_button;
  JoystickButton turn_right_button;

  Solenoid left_solenoid;
  Solenoid right_solenoid;

  //Compressor compressor;

  DriverStationLCD *ds_lcd;

 public:
  Robot(void):
      myRobot(1, 2, 3, 4),
      stick(1),
      stick2(2),
      solenoid_up_button(&stick, 3),
      solenoid_down_button(&stick, 2),
      turn_left_button(&stick, 4),
      turn_right_button(&stick, 5),
      left_solenoid(1),
      right_solenoid(8) {
      //compressor() //TODO: add constructor parameters

    myRobot.SetExpiration(0.1);

    ds_lcd = DriverStationLCD::GetInstance();
  }

  void Autonomous(void) {

  }

  void OperatorControl(void) {
    myRobot.SetSafetyEnabled(true);

    float x, y, twist;
    bool solenoid_up, solenoid_down, left, right;

    while (IsOperatorControl()) {

      //sets floats for robot movement.  "x" and "y" are floats between -1 -> 1 for joystick input (up, right positive) (down, left negative)
      x = stick.GetX();
      y = stick.GetY();

      //bool(eans) for if the buttons are pushed to indicate turning.
      left = turn_left_button.Get();
      right = turn_right_button.Get();

      //if left turning button is pushed (default 4), set turning number between -1 -> 0
      if (left) {
        twist = -1 * TURNING_RATE;
      }

      //if right turning button is pushed (default 5), set turning number between 0 -> 1
      if (right) {
        twist = 1 * TURNING_RATE;
      }

      //if both buttons or neither buttons are pushed, do nothing.  Avoids priority conflicts between left and right buttons.
      if (left && right) {
        twist = 0;
      } else if (!left && !right) {
        twist = 0;
      }

      //bool(eans) for if the buttons are pushed to indicate solenoid turning (pneumatics)
      solenoid_up = solenoid_up_button.Get();
      solenoid_down = solenoid_down_button.Get();

      //various printlns
      //Line 1: X, Y joystick inputs.
      //Line 2: Solenoid UP Button Reading (TRUE | FALSE)
      //Line 3: Solenoid DOWN Button Reading (TRUE | FALSE)
      //Line 4: Turning number (between -1 -> 1, can be NULL);
      ds_lcd->PrintfLine(DriverStationLCD::kUser_Line1,
                         "J1X: %.3f J1Y: %.3f", x, y);

      ds_lcd->PrintfLine(DriverStationLCD::kUser_Line2, "solenoid_up: %s",
                         solenoid_up ? "On" : "Off");

      ds_lcd->PrintfLine(DriverStationLCD::kUser_Line3, "solenoid_down: %s",
                         solenoid_down ? "On" : "Off");

      ds_lcd->PrintfLine(DriverStationLCD::kUser_Line4,
                         "Turn Number: %s", twist);

      //Drive command
      myRobot.MecanumDrive_Cartesian(x, y, twist);

      //Solenoid button if stack.  Moves solenoids if appropriate buttons are pushed.
      if (solenoid_up && !solenoid_down) {
        left_solenoid.Set(true);
        right_solenoid.Set(true);
      }

      if (solenoid_down && !solenoid_up) {
        left_solenoid.Set(false);
        right_solenoid.Set(false);
      }

      Wait(0.005);

      ds_lcd->UpdateLCD();
    }
  }

};

START_ROBOT_CLASS(Robot);
