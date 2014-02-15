// This command turns on the compressor

#ifndef _COMMANDS_COMPRESSORON_H_
#define _COMMANDS_COMPRESSORON_H_

#include "Commands/Command.h"
#include "../Robot.h"

class CompressorOn: public Command {
 public:
  explicit CompressorOn(bool on);

  virtual void Initialize() override;
  virtual void Execute() override;
  virtual bool IsFinished() override;
  virtual void End() override;
  virtual void Interrupted() override;

 private:
  bool compressor_on;
};

#endif
