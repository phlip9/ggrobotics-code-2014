// Hardware to software map.

#include "HardwareMap.h"

#include "SpeedController.h"
#include "Talon.h"
#include "LiveWindow/LiveWindow.h"

#include "Config.h"
#include "Logging.h"

HardwareMap::HardwareMap()
  : front_left_motor(CONFIG::MotorFrontLeftDrive()),
    rear_left_motor(CONFIG::MotorRearLeftDrive()),
    front_right_motor(CONFIG::MotorFrontRightDrive()),
    rear_right_motor(CONFIG::MotorRearRightDrive()),
    gyro(CONFIG::GyroChannel()) {

}

HardwareMap::~HardwareMap() {

}

void HardwareMap::init() {
  log_info("init()");

  LiveWindow *live_window = LiveWindow::GetInstance();

  // Add Talon motors
  live_window->AddActuator("Drive", "Front Left Motor", &front_left_motor);
  live_window->AddActuator("Drive", "Rear Left Motor", &rear_left_motor);
  live_window->AddActuator("Drive", "Front Right Motor", &front_right_motor);
  live_window->AddActuator("Drive", "Rear Right Motor", &rear_right_motor);

  live_window->AddSensor("Drive", "Gyro", &gyro);
}
