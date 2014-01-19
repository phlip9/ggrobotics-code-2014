// Robot config

#include "Config.h"
#include "Preferences.h"

int CONFIG::MotorFrontLeftDrive() {
  return Preferences::GetInstance()->GetInt("MotorFrontLeftDrive", 3);
}

int CONFIG::MotorRearLeftDrive() {
  return Preferences::GetInstance()->GetInt("MotorRearLeftDrive", 4);
}

int CONFIG::MotorFrontRightDrive() {
  return Preferences::GetInstance()->GetInt("MotorFrontRightDrive", 1);
}

int CONFIG::MotorRearRightDrive() {
  return Preferences::GetInstance()->GetInt("MotorRearRightDrive", 2);
}

int CONFIG::GyroChannel() {
  return Preferences::GetInstance()->GetInt("GyroChannel", 1);
}

float CONFIG::GyroScalingConstant() {
  return Preferences::GetInstance()->GetFloat("GyroScalingConstant", -0.00875);
}

float CONFIG::GyroThreshold() {
  return Preferences::GetInstance()->GetFloat("GyroThreshold", 1.0);
}

int CONFIG::JoystickDrive() {
  return Preferences::GetInstance()->GetInt("JoystickDrive", 1);
}
