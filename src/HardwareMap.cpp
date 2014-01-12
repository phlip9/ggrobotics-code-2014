// Hardware to software map.

#include "HardwareMap.h"

#include "SpeedController.h"
#include "Jaguar.h"
#include "LiveWindow/LiveWindow.h"

#include "Config.h"
#include "Logging.h"

HardwareMap::HardwareMap()
  : front_left_motor(new Jaguar(CONFIG::MotorFrontLeftDrive())),
    rear_left_motor(new Jaguar(CONFIG::MotorRearLeftDrive())),
    front_right_motor(new Jaguar(CONFIG::MotorFrontRightDrive())),
    rear_right_motor(new Jaguar(CONFIG::MotorRearRightDrive())) {

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

  // Add Jaguar motors
  live_window->AddActuator("Drive", "Front Left Motor", front_left_motor);
  live_window->AddActuator("Drive", "Rear Left Motor", rear_left_motor);
  live_window->AddActuator("Drive", "Front Right Motor", front_right_motor);
  live_window->AddActuator("Drive", "Rear Right Motor", rear_right_motor);
}
