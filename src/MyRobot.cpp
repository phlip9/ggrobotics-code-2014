#include "WPILib.h"

class Robot : public SimpleRobot
{
	RobotDrive myRobot; // robot drive system
	Joystick stick; //only joystick
	Joystick stick2;

	DriverStationLCD *ds_lcd;

public:
	Robot(void):
		myRobot(1, 2, 3, 4),	// these must be initialized in the same order as they are declared above.
		stick(1),
		stick2(2)
	{
		myRobot.SetExpiration(0.1);
		//myRobot.SetInvertedMotor(myRobot.kFrontLeftMotor, true);
		//myRobot.SetInvertedMotor(myRobot.kRearLeftMotor, true);

		//create objects
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
			//Read Joystick 1 Values
			x = stick.GetX();
			y = stick.GetY();

			myRobot.MecanumDrive_Cartesian(x, y, 0); // drive with Mechn0m weels (use right stick)
			Wait(0.005);  // wait for a motor update time

			ds_lcd->UpdateLCD();
		}
	}
};

START_ROBOT_CLASS(Robot);
