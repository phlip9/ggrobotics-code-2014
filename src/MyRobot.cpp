#include "WPILib.h"

class Robot : public SimpleRobot
{
	RobotDrive myRobot;
	Joystick stick;
	Joystick stick2;

    JoystickButton solenoid_up_button;
    JoystickButton solenoid_down_button;

    DoubleSolenoid left_solenoid;
    DoubleSolenoid right_solenoid;

    //Compressor compressor;

	DriverStationLCD *ds_lcd;

public:
	Robot(void):
		myRobot(1, 2, 3, 4),
		stick(1),
		stick2(2),
        solenoid_up_button(&stick, 3),
        solenoid_down_button(&stick, 2),
        left_solenoid(1, 4, 2),
        right_solenoid(2, 2, 4)
        //compressor() //TODO: add constructor parameters
	{
		myRobot.SetExpiration(0.1);

		ds_lcd = DriverStationLCD::GetInstance();
	}

	void Autonomous(void)
	{

	}

	void OperatorControl(void)
	{
		myRobot.SetSafetyEnabled(true);

		float x, y;
        bool solenoid_up, solenoid_down;

		while (IsOperatorControl())
		{
			x = stick.GetX();
			y = stick.GetY();

            solenoid_up = solenoid_up_button.Get();
            solenoid_down = solenoid_down_button.Get();

            ds_lcd->PrintfLine(DriverStationLCD::kUser_Line1, "J1X: %.3f J1Y: %.3f", x, y);

            ds_lcd->PrintfLine(DriverStationLCD::kUser_Line2, "solenoid_up: %s",
                    solenoid_up ? "On" : "Off");

            ds_lcd->PrintfLine(DriverStationLCD::kUser_Line3, "solenoid_down: %s",
                    solenoid_down ? "On" : "Off");

			myRobot.MecanumDrive_Cartesian(x, y, 0);

            if (solenoid_up && !solenoid_down) {
                left_solenoid.Set(DoubleSolenoid::kForward);
                right_solenoid.Set(DoubleSolenoid::kForward);
            }

            if (solenoid_down && !solenoid_up) {
                left_solenoid.Set(DoubleSolenoid::kReverse);
                right_solenoid.Set(DoubleSolenoid::kReverse);
            }

            if (!solenoid_up && !solenoid_down) {
                left_solenoid.Set(DoubleSolenoid::kOff);
                right_solenoid.Set(DoubleSolenoid::kOff);
            }

			Wait(0.005);

			ds_lcd->UpdateLCD();
		}
	}

};

START_ROBOT_CLASS(Robot);
