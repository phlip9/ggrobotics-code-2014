// Robot drive subsystem

#include "Drive.h"

#include "../Commands/BackgroundDrive.h"

Drive::Drive(const HardwareMap& hardware_map)
    : Subsystem("Drive"),
      robot_drive(hardware_map.front_left_motor,
                  hardware_map.rear_left_motor,
                  hardware_map.front_right_motor,
                  hardware_map.rear_right_motor) {

  robot_drive.SetExpiration(0.1);
}

Drive::~Drive() { }

void Drive::InitDefaultCommand() {
  SetDefaultCommand(new BackgroundDrive());
}

void Drive::mecanum_drive(Joystick& drive_stick) {
  float magnitude, direction, rotation;
  magnitude = drive_stick.GetMagnitude();
  direction = drive_stick.GetDirectionDegrees();
  rotation = 0.0;
  robot_drive.MecanumDrive_Cartesian(magnitude, direction, rotation);
}
