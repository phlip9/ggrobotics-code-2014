#ifndef _COMMANDS_AUTONOMOUS_DRIVE_H_
#define _COMMANDS_AUTONOMOUS_DRIVE_H_

#include "Commands/Command.h"
#include "Timer.h"

class AutonomousDrive : public Command {
  public:
   explicit AutonomousDrive(double seconds, float power);

   virtual void Initialize() override;
   virtual void Execute() override;
   virtual bool IsFinished() override;
   virtual void End() override;
   virtual void Interrupted() override;

  private:
   double m_seconds;
   float m_power;
   Timer m_timer;

};

#endif

