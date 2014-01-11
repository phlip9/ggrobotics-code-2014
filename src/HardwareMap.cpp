// Hardware to software map.

#include "HardwareMap.h"

#include "SpeedController.h"
#include "Jaguar.h"
#include "LiveWindow/LiveWindow.h"

#include "Config.h"

HardwareMap::HardwareMap()
  : front_left_motor(new Jaguar(CONFIG::FRONT_LEFT_DRIVE)),
    rear_left_motor(new Jaguar(CONFIG::REAR_LEFT_DRIVE)),
    front_right_motor(new Jaguar(CONFIG::FRONT_RIGHT_DRIVE)),
    rear_right_motor(new Jaguar(CONFIG::REAR_RIGHT_DRIVE)) {

}

HardwareMap::~HardwareMap() {
  delete front_left_motor;
  delete rear_left_motor;
  delete front_right_motor;
  delete rear_left_motor;
}

void HardwareMap::init() {
  LiveWindow *live_window = LiveWindow::GetInstance();

  // Add Jaguar motors
  live_window->AddActuator("Drive", "Front Left Motor", (Jaguar*) front_left_motor);
  live_window->AddActuator("Drive", "Rear Left Motor", (Jaguar*) rear_left_motor);
  live_window->AddActuator("Drive", "Front Right Motor", (Jaguar*) front_right_motor);
  live_window->AddActuator("Drive", "Rear Right Motor", (Jaguar*) rear_right_motor);
}
