// Hardware to software map.

#include "HardwareMap.h"

#include "SensorBase.h"
#include "LiveWindow/LiveWindow.h"
#include "Gyro.h"

#include "Config.h"
#include "Logging.h"

HardwareMap::HardwareMap()
  : front_left_motor(CONFIG::HARDWARE::drive_front_left),
    rear_left_motor(CONFIG::HARDWARE::drive_rear_left),
    front_right_motor(CONFIG::HARDWARE::drive_front_right),
    rear_right_motor(CONFIG::HARDWARE::drive_rear_right),
    gyro(CONFIG::HARDWARE::drive_gyro),
    wheel_motor(CONFIG::HARDWARE::arm_wheel),
    front_arm_motor(CONFIG::HARDWARE::front_arm),
    back_arm_motor(CONFIG::HARDWARE::back_arm) {

  log_info("HardwareMap()");
}

HardwareMap::~HardwareMap() {
  log_info("~HardwareMap()");
}

void HardwareMap::init() {
  log_info("init()");

  bool check_gyro = SensorBase::CheckAnalogModule(CONFIG::HARDWARE::drive_gyro);
  log_debug("Gyro detected: %s", check_gyro ? "true" : "false");

  LiveWindow *live_window = LiveWindow::GetInstance();

  // Add Talon motors
  live_window->AddActuator("Drive", "Front Left Motor", &front_left_motor);
  live_window->AddActuator("Drive", "Rear Left Motor", &rear_left_motor);
  live_window->AddActuator("Drive", "Front Right Motor", &front_right_motor);
  live_window->AddActuator("Drive", "Rear Right Motor", &rear_right_motor);

  live_window->AddSensor("Drive", "Gyro", &gyro);
}
