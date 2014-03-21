#include "AutonomousCommand.h"

#include "Commands/CommandGroup.h"
#include "Commands/WaitCommand.h"

#include "../Subsystems/Drive.h"
#include "../Subsystems/MotorSubsystem.h"
#include "MotorMove.h"
#include "AutonomousDrive.h"

#include "../Logging.h"

AutonomousCommand::AutonomousCommand(Drive *drive,
                                     MotorSubsystem *arm_wheels,
                                     MotorSubsystem *front_arm)
  : CommandGroup("AutonomousCommand") {

  log_debug("AutonomousCommand()");

  AddSequential(new AutonomousDrive(drive, 4.0, 0.50));

  AddParallel(
      new MotorMove("WheelSpinAutonomous", arm_wheels, Direction::DOWN),
      3.0); //timeout

  m_arm_n_wheels = new CommandGroup("Arm And Wheels");

  m_arm_n_wheels->AddSequential(
      new MotorMove("FrontArmUp", front_arm, Direction::UP),
      0.1); //timeout

  m_arm_n_wheels->AddSequential(new WaitCommand(0.75));

  m_arm_n_wheels->AddSequential(
      new MotorMove("FrontArmDown", front_arm, Direction::DOWN),
      0.2); //timeout

  AddParallel(m_arm_n_wheels);
}

AutonomousCommand::~AutonomousCommand() {
  delete m_arm_n_wheels;
}
