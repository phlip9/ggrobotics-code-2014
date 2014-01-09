// Hardware to software map.

#include "HardwareMap.h"
#include "LiveWindow/LiveWindow.h"

HardwareMap::HardwareMap()
    :       hang_solenoid_left(1),
      hang_solenoid_right(8) {

  drivetrain.setExpiration(0.1);
}

HardwareMap::~HardwareMap() { }

void HardwareMap::AddToLiveWindow() {
  LiveWindow *live_window = LiveWindow::GetInstance();

  // Add Jaguar motors
  live_window->AddActuator("Drive", "Front Left Motor", front_left_motor);
  live_window->AddActuator("Drive", "Rear Left Motor", rear_left_motor);
  live_window->AddActuator("Drive", "Front Right Motor", front_right_motor);
  live_window->AddActuator("Drive", "Rear Right Motor", rear_right_motor);

  // Add Hang Solenoids
  live_window->AddActuator("Hang", "Hang Solenoid Left", hang_solenoid_left);
  live_window->AddActuator("Hang", "Hang Solenoid Right", hang_solenoid_right);

}
