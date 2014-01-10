// Robot drive subsystem

#import "Drive.h"
#import "Commands/BackgroundDrive.h"

Drive::Drive()
    : Subsystem("Drive"),
      robot_drive(Robot::hardware_map->front_left_motor,
                  Robot::hardware_map->rear_left_motor,
                  Robot::hardware_map->front_right_motor,
                  Robot::hardware_map->rear_right_motor) {

  robot_drive.setExpiration(0.1);
}

Drive::~Drive() { }

void Drive::InitDefaultCommand() {
  SetDefaultCommand(new BackgroundDrive());
}

void Drive::mecanum_drive(float x, float y, float rotation, float gyro_angle = 0.0) {
  robot_drive.MecanumDrive_Cartesian(x, y, rotation, gyro_angle);
}
