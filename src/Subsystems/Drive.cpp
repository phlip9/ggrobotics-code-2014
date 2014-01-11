// Robot drive subsystem

#include "Drive.h"

#include "../Robot.h"
#include "../Commands/BackgroundDrive.h"

Drive::Drive()
    : Subsystem("Drive"),
      robot_drive(Robot::hardware_map->front_left_motor,
                  Robot::hardware_map->rear_left_motor,
                  Robot::hardware_map->front_right_motor,
                  Robot::hardware_map->rear_right_motor) {

  robot_drive.SetExpiration(0.1);
}

Drive::~Drive() { }

void Drive::InitDefaultCommand() {
  SetDefaultCommand(new BackgroundDrive());
}

void Drive::mecanum_drive(Joystick &drive_stick) {
  float magnitude, direction, rotation;
  magnitude = drive_stick.GetMagnitude();
  direction = drive_stick.GetDirectionDegrees();
  rotation = 0.0;
  robot_drive.MecanumDrive_Cartesian(magnitude, direction, rotation);
}
