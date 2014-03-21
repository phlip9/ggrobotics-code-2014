#include "HardwareMap.h"

#include "SmartDashboard/SmartDashboard.h"
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
               CONFIG::HARDWARE::compressor_relay) {

  log_info("HardwareMap()");
}

HardwareMap::~HardwareMap() {
  log_info("~HardwareMap()");
}

void HardwareMap::init() {
  log_info("init()");

  // Add hardware to the live window
  // You can then debug each hardware object in the driver station test mode
  // on the smart dashboard.

  LiveWindow *lw = LiveWindow::GetInstance();

  lw->AddActuator("Drive", "Front Left Motor", &front_left_motor);
  lw->AddActuator("Drive", "Rear Left Motor", &rear_left_motor);
  lw->AddActuator("Drive", "Front Right Motor", &front_right_motor);
  lw->AddActuator("Drive", "Rear Right Motor", &rear_right_motor);

  lw->AddActuator("Arm", "Front Arm Motor", &front_arm_motor);
  lw->AddActuator("Arm", "Wheel Motor", &wheel_motor);

  lw->AddActuator("Shooter", "Left Launch Solenoid", &launch_solenoid_left);
  lw->AddActuator("Shooter", "Right Launch Solenoid", &launch_solenoid_right);
  lw->AddSensor("Shooter", "Compressor", &compressor);
}

void HardwareMap::UpdateSmartDashboard() {
  SmartDashboard::PutNumber("Front Left Motor", front_left_motor.Get());
  SmartDashboard::PutNumber("Rear Left Motor", rear_left_motor.Get());
  SmartDashboard::PutNumber("Front Right Motor", front_right_motor.Get());
  SmartDashboard::PutNumber("Rear Right Motor", rear_right_motor.Get());

  SmartDashboard::PutNumber("Front Arm Motor", front_arm_motor.Get());
  SmartDashboard::PutNumber("Wheel Motor", wheel_motor.Get());
}
