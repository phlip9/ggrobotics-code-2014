// This command turns on the compressor

#ifndef _COMMANDS_COMPRESSORON_H_
#define _COMMANDS_COMPRESSORON_H_

#include "Commands/Command.h"

class CompressorOn: public Command {
 public:
  CompressorOn();

  virtual void Initialize() override;
  virtual void Execute() override;
  virtual bool IsFinished() override;
  virtual void End() override;
  virtual void Interrupted() override;
};

#endif
