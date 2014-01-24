// Robot config

#include "Config.h"

#include "Preferences.h"

float CONFIG::GyroScalingConstant() {
  return Preferences::GetInstance()->GetFloat("GyroScalingConstant", -0.00875);
}

float CONFIG::GyroThreshold() {
  return Preferences::GetInstance()->GetFloat("GyroThreshold", 1.0);
}
