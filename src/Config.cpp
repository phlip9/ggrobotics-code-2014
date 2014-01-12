// Robot config

#include "Config.h"
#include "Preferences.h"

int CONFIG::MotorFrontLeftDrive() {
  return Preferences::GetInstance()->GetInt("MotorFrontLeftDrive", 1);
}

int CONFIG::MotorRearLeftDrive() {
  return Preferences::GetInstance()->GetInt("MotorRearLeftDrive", 2);
}

int CONFIG::MotorFrontRightDrive() {
  return Preferences::GetInstance()->GetInt("MotorFrontRightDrive", 3);
}

int CONFIG::MotorRearRightDrive() {
  return Preferences::GetInstance()->GetInt("MotorRearRightDrive", 4);
}

int CONFIG::JoystickDrive() {
  return Preferences::GetInstance()->GetInt("JoystickDrive", 1);
}