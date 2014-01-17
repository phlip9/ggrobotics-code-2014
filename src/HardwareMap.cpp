// Hardware to software map.

#include "HardwareMap.h"

#include "SpeedController.h"
#include "Talon.h"
#include "LiveWindow/LiveWindow.h"

#include "Config.h"
#include "Logging.h"

HardwareMap::HardwareMap()
  : front_left_motor(new Talon(CONFIG::MotorFrontLeftDrive())),
    rear_left_motor(new Talon(CONFIG::MotorRearLeftDrive())),
    front_right_motor(new Talon(CONFIG::MotorFrontRightDrive())),
    rear_right_motor(new Talon(CONFIG::MotorRearRightDrive())),
    gyro(1) {

}

HardwareMap::~HardwareMap() {
  delete front_left_motor;
  delete rear_left_motor;
  delete front_right_motor;
  delete rear_left_motor;
}

void HardwareMap::init() {
  log_info("init()");

  LiveWindow *live_window = LiveWindow::GetInstance();

  // Add Talon motors
  live_window->AddActuator("Drive", "Front Left Motor", dynamic_cast<Talon*>(front_left_motor));
  live_window->AddActuator("Drive", "Rear Left Motor", dynamic_cast<Talon*>(rear_left_motor));
  live_window->AddActuator("Drive", "Front Right Motor", dynamic_cast<Talon*>(front_right_motor));
  live_window->AddActuator("Drive", "Rear Right Motor", dynamic_cast<Talon*>(rear_right_motor));
}
