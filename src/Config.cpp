// Robot config

#include "Config.h"

#include "Preferences.h"

float CONFIG::GyroScalingConstant() {
  return Preferences::GetInstance()->GetFloat("GyroScalingConstant", -0.00875);
}

float CONFIG::GyroThreshold() {
  return Preferences::GetInstance()->GetFloat("GyroThreshold", 1.0);
}

float CONFIG::GyroTimeout() {
  return Preferences::GetInstance()->GetFloat("GyroTimeout", 0.25);
}

float CONFIG::ArmWheelPower() {
  return Preferences::GetInstance()->GetFloat("ArmWheelPower", 0.5);
}

float CONFIG::FrontArmPowerUp() {
  return Preferences::GetInstance()->GetFloat("FrontArmPowerUp", -0.50);
}

float CONFIG::FrontArmPowerDown() {
  return Preferences::GetInstance()->GetFloat("FrontArmPowerDown", 0.30);
}
