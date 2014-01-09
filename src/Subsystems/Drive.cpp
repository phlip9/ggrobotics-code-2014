// Robot drive subsystem

#import "Drive.h"

Drive::Drive()
    : Subsystem("Drive"),
      front_left_motor(1),
      rear_left_motor(2),
      front_right_motor(3),
      rear_right_motor(4),
      drivetrain(&front_left_motor, &rear_left_motor,
                 &front_right_motor, &rear_right_motor) {

  drivetrain.setExpiration(0.1);
}
