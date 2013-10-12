#include "WPILib.h"

class Robot : public SimpleRobot
{
	RobotDrive myRobot;
	Joystick stick;
	Joystick stick2;

	DriverStationLCD *ds_lcd;

public:
	Robot(void):
		myRobot(1, 2, 3, 4),
		stick(1),
		stick2(2)
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

		while (IsOperatorControl())
		{
			x = stick.GetX();
			y = stick.GetY();

            ds_lcd->PrintfLine(DriverStationLCD::kUser_Line1, "J1X: %.3f J1Y: %.3f", x, y);

			myRobot.MecanumDrive_Cartesian(x, y, 0);
			Wait(0.005);

			ds_lcd->UpdateLCD();
		}
	}
};

START_ROBOT_CLASS(Robot);
