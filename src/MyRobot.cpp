#include "WPILib.h"

class Robot : public SimpleRobot
{
	RobotDrive myRobot; // robot drive system
	Joystick stick; //only joystick
	Joystick stick2;
	Jaguar fireArm;
	Jaguar shootingWheel;
	Jaguar jackMotor;

	DriverStationLCD *ds_lcd;
	Servo *servoFront;
	Servo *servoBack;
	Gyro *gyro;
	Gyro *jackGyro;
	DigitalInput *switch1;
	DigitalInput *switch2;
	DigitalInput *jackStopDown;
	DigitalInput *jackStopUp;
	Encoder *encoder;

public:
	Robot(void):
		myRobot(1, 2, 3, 4),	// these must be initialized in the same order as they are declared above.
		stick(1),
		stick2(2),
		fireArm(5),
		shootingWheel(6),
		jackMotor(7)
	{
		myRobot.SetExpiration(0.1);
		myRobot.SetInvertedMotor(myRobot.kFrontLeftMotor, true);
		myRobot.SetInvertedMotor(myRobot.kRearLeftMotor, true);
		
		//create objects
		ds_lcd = DriverStationLCD::GetInstance();	
		servoFront = new Servo(8);
		servoBack = new Servo(9);
		gyro = new Gyro(1);
		jackGyro = new Gyro(2);
		switch1 = new DigitalInput(1);
		switch2 = new DigitalInput(3);
		jackStopDown = new DigitalInput(4);
		jackStopUp = new DigitalInput(5);
		encoder = new Encoder (7,8);
	}
	
	void Autonomous(void)
	{		
		myRobot.SetSafetyEnabled(false);
		
		ds_lcd->PrintfLine(DriverStationLCD::kUser_Line1, "Autonomous mode begun");
		ds_lcd->UpdateLCD();
		
		int frisbees, switch1Val, switch2Val, direction;
		float armSpeed;
		frisbees = 3;
		direction = 0;
		armSpeed = 0.45;
		
		
		servoFront->Set(0.0);
		servoBack->Set(0.8);
		
		//Jack up
		jackMotor.Set(0.6);
		Wait(2.0);
		jackMotor.Set(0.0);	
		
		//shootingWheel.Set(-0.920472);

		while (!(frisbees == 0 && direction ==0))
		{
			switch1Val = switch1->Get();
			switch2Val = switch2->Get();

			if (switch1Val && direction == -1)
				{
					direction = 0;
					fireArm.Set(0);
					frisbees --;
				}
			else if (frisbees && direction == 0)
				{
					direction = 1;
					if (frisbees == 2)
					{
						servoBack->Set(0.0);
						Wait(2.5);
					}
					else if (frisbees == 1)
					{
						servoFront->Set(0.8);
						Wait(2.5);
					}
					
					fireArm.Set(armSpeed);
				}
			else if (switch2Val && direction != -1)
				{
					direction = -1;
					fireArm.Set(-armSpeed);
				}
			
			//shootingWheel.Set(0.0);
			
			ds_lcd->PrintfLine(DriverStationLCD::kUser_Line6, "Frisbees: %d", frisbees);
			ds_lcd->UpdateLCD();
		}
		
		//Jack Down
		/*jackMotor.Set(-0.5);
		Wait(1.5);
		jackMotor.Set(0.0);*/
	}


	void OperatorControl(void)
	{
		myRobot.SetSafetyEnabled(true);
		
		float x, y, twist, throttle, gyroAngle, platformAngle, axis_5, axis_4;
		float stick2_x, stick2_y;
		int switch1Value, switch2Value, jackUp, jackDown;
		bool gyroEnabled, firing, stowed;
		int direction, encoderDistance; //0=idle 1 = forward -1 = backward
		gyro->Reset();
		jackGyro->Reset();
		gyroEnabled = true;
		direction = 0;
		firing = false;
		stowed = false;
		jackUp = 0;
		jackDown = 0;
		switch1Value = 0;
		switch2Value = 0;
		jackMotor.Set(0.0);
		fireArm.Set(0.0);
		servoFront->Set(0.8);
		servoBack->Set(0.0);
		
		while (IsOperatorControl())
		{
			//Read Joystick 1 Values
			x = stick.GetX();
			y = stick.GetY();
			twist = stick.GetRawAxis(6);
			throttle = stick.GetThrottle();
			axis_5 = stick.GetRawAxis(5)/10;
			axis_4 = stick.GetRawAxis(4);
			
			/*if (stick.GetRawButton(9)){
				gyroEnabled = false;
			}
			
			if (stick.GetRawButton(10)){
				gyroEnabled = true;
			}*/
			
			if (stick.GetRawButton(9)){
				servoFront->Set(0.15);
			}
						
			if (stick.GetRawButton(10)){
				servoFront->Set(0.8);
			}
			
			if (stick.GetRawButton(11)){
				servoBack->Set(0.8);
			}
			if (stick.GetRawButton(12)){
				servoBack->Set(0.0);
			}		
			
			if (stick.GetRawButton(5)){
				gyro->Reset();
			}
			
			if (stick.GetRawButton(3)){
				twist = 0.375;
			}
			if (stick.GetRawButton(4)){
				twist = -0.375;
			}
			
			//Read Joystick 2 Values
			stick2_x = stick2.GetX();
			stick2_y = stick2.GetY();
			
			if (stick2.GetRawButton(1)){
				shootingWheel.Set(-0.920472 + axis_5);
			}
			if (stick2.GetRawButton(2)){
				shootingWheel.Set(0.0);
			}
			
		
			//Read Gyro Values
			gyroAngle = gyro->GetAngle();
			platformAngle =  jackGyro->GetAngle();
			
			//Read Switch Values
			switch1Value = switch1->Get();
			switch2Value = switch2->Get();
			jackUp = jackStopUp->Get();
			jackDown = jackStopDown->Get();		
			
			//Throttle Calculations
			throttle = throttle * -1;
			throttle = (throttle + 1) / 2;
			x = x * throttle;
			y = y * throttle;
			twist = twist * throttle;
			
			//Drive code			
			if (x < 0.05 && y < 0.05 && twist < 0.05){
				gyro->Reset();
			}
			
			if (!(twist > 0.05) && !(twist < -0.05) && gyroEnabled){
				if (gyroAngle > 1 || gyroAngle < -1){
					twist = gyroAngle * -0.0125;
				}	
			}
			else{
				gyro->Reset();
			}
			
			twist = twistSaturation(twist, 1);
			
			myRobot.MecanumDrive_Cartesian(x,y,twist); // drive with Mechn0m weels (use right stick)
			Wait(0.005);  // wait for a motor update time
			
			//Firing arm code
			if (stick2.GetRawButton(3))
			{
				if (!switch2Value){
					fireArm.Set(0.45);
					direction = 1;
				}
				else{
					fireArm.Set(0.0);
					direction = 0;
				}						
			}
			else if (switch1Value && direction == -1)
			{
				direction = 0;
				fireArm.Set(0);
			}
			else if (stick.GetRawButton(1) && direction == 0)
			{
				direction = 1;
				fireArm.Set(0.45);
			}
			else if (switch2Value && direction == 1)
			{
				direction = -1;
				fireArm.Set(-0.45);
			}
			
			
			
			//Jack code
			if ((stick2_y > 0.0 && jackUp))
			{
				jackMotor.Set(0.0);
			}
			else if ((stick2_y < 0.0 && jackDown))
			{
				jackMotor.Set(0.0);
			}
			else
			{
				jackMotor.Set(stick2_y);
			}
			
			//encoder
			encoderDistance = encoder->GetRaw();
	
			if (gyroEnabled){
				ds_lcd->PrintfLine(DriverStationLCD::kUser_Line1, "Gyro is goot");
			}
			else{
				ds_lcd->PrintfLine(DriverStationLCD::kUser_Line1, "Gyro Disabled");
			}
			if (direction == 0) {
				ds_lcd->PrintfLine(DriverStationLCD::kUser_Line2, "Firing Status: Ready");
			}
			else {
				ds_lcd->PrintfLine(DriverStationLCD::kUser_Line2, "Firing Status: Firing");			
			}
			
			ds_lcd->PrintfLine(DriverStationLCD::kUser_Line5, "encoder: %d", encoderDistance);
			
			ds_lcd->UpdateLCD();
		}
	}
	float twistSaturation (float twist,float max){
			if (twist > max){
				return max;
			}
			if (twist < -max){
				return -max;
			}
			return twist;
		}
};
START_ROBOT_CLASS(Robot);
