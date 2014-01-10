// Hardware to software map.

#include "HardwareMap.h"
#include "Config.h"
#include "LiveWindow/LiveWindow.h"

HardwareMap::HardwareMap()
    : front_left_motor(CONFIG::FRONT_LEFT_DRIVE),
      rear_left_motor(CONFIG::REAR_LEFT_DRIVE),
      front_right_motor(CONFIG::FRONT_RIGHT_DRIVE),
      rear_right_motor(CONFIG::REAR_RIGHT_DRIVE) {

}

HardwareMap::~HardwareMap() { }

void HardwareMap::init() {
  LiveWindow *live_window = LiveWindow::GetInstance();

  // Add Jaguar motors
  live_window->AddActuator("Drive", "Front Left Motor", &front_left_motor);
  live_window->AddActuator("Drive", "Rear Left Motor", &rear_left_motor);
  live_window->AddActuator("Drive", "Front Right Motor", &front_right_motor);
  live_window->AddActuator("Drive", "Rear Right Motor", &rear_right_motor);
}
