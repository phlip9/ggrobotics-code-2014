// Robot config

#include "Config.h"

#include "Preferences.h"

float CONFIG::ArmWheelPower() {
  return Preferences::GetInstance()->GetFloat("ArmWheelPower", 1.0);
}

float CONFIG::FrontArmPowerUp() {
  return Preferences::GetInstance()->GetFloat("FrontArmPowerUp", -0.80);
}

float CONFIG::FrontArmPowerDown() {
  return Preferences::GetInstance()->GetFloat("FrontArmPowerDown", 0.80);
}
