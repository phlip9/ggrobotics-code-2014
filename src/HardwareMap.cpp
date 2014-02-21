#include "HardwareMap.h"

#include "SensorBase.h"
#include "LiveWindow/LiveWindow.h"
#include "Compressor.h"

#include "Config.h"
#include "Logging.h"

HardwareMap::HardwareMap()
  : front_left_motor(CONFIG::HARDWARE::drive_front_left),
    rear_left_motor(CONFIG::HARDWARE::drive_rear_left),
    front_right_motor(CONFIG::HARDWARE::drive_front_right),
    rear_right_motor(CONFIG::HARDWARE::drive_rear_right),
    wheel_motor(CONFIG::HARDWARE::arm_wheel),
    front_arm_motor(CONFIG::HARDWARE::front_arm),
    launch_solenoid_right(CONFIG::HARDWARE::launch_solenoid_right),
    launch_solenoid_left(CONFIG::HARDWARE::launch_solenoid_left),
    compressor(CONFIG::HARDWARE::compressor_switch,
               CONFIG::HARDWARE::compressor_relay){

  log_info("HardwareMap()");
}

HardwareMap::~HardwareMap() {
  log_info("~HardwareMap()");
}

void HardwareMap::init() {
  log_info("init()");

  // Add hardware to the live window
  // You can then debug each hardware object in the driver station test mode
  // and the smart dashboard.

  LiveWindow *live_window = LiveWindow::GetInstance();

  live_window->AddActuator("Drive", "Front Left Motor", &front_left_motor);
  live_window->AddActuator("Drive", "Rear Left Motor", &rear_left_motor);
  live_window->AddActuator("Drive", "Front Right Motor", &front_right_motor);
  live_window->AddActuator("Drive", "Rear Right Motor", &rear_right_motor);

  live_window->AddActuator("Arm", "Front Arm Motor", &front_arm_motor);
  live_window->AddActuator("Arm", "Wheel Motor", &wheel_motor);

  live_window->AddActuator("Shooter", "Left Launch Solenoid", &launch_solenoid_left);
  live_window->AddActuator("Shooter", "Right Launch Solenoid", &launch_solenoid_right);
  live_window->AddSensor("Shooter", "Compressor", &compressor);
}
