// Hardware to software map.

#include "HardwareMap.h"

#include "SensorBase.h"
#include "LiveWindow/LiveWindow.h"
#include "Gyro.h"

#include "Config.h"
#include "Logging.h"

HardwareMap::HardwareMap()
  : front_left_motor(CONFIG::drive_motor_front_left),
    rear_left_motor(CONFIG::drive_motor_rear_left),
    front_right_motor(CONFIG::drive_motor_front_right),
    rear_right_motor(CONFIG::drive_motor_rear_right),
    gyro(CONFIG::gyro_channel) {

  log_info("HardwareMap()");
}

HardwareMap::~HardwareMap() {
  log_info("~HardwareMap()");
}

void HardwareMap::init() {
  log_info("init()");

  bool check_gyro = SensorBase::CheckAnalogModule(CONFIG::gyro_channel);
  log_debug("Gyro detected: %s", check_gyro ? "true" : "false");

  LiveWindow *live_window = LiveWindow::GetInstance();

  // Add Talon motors
  live_window->AddActuator("Drive", "Front Left Motor", &front_left_motor);
  live_window->AddActuator("Drive", "Rear Left Motor", &rear_left_motor);
  live_window->AddActuator("Drive", "Front Right Motor", &front_right_motor);
  live_window->AddActuator("Drive", "Rear Right Motor", &rear_right_motor);

  live_window->AddSensor("Drive", "Gyro", &gyro);
}
