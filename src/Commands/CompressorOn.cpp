#include "CompressorOn.h"

#include "../Robot.h"
#include "../Logging.h"

CompressorOn::CompressorOn()
  : Command("Compressor") {

  log_debug("Compressor()");

}

void CompressorOn::Initialize() {
  log_debug("Initialize()");
}

void CompressorOn::Execute() {
  Robot::hardware_map()->compressor.Start();
}

bool CompressorOn::IsFinished() {
  return true;
}

void CompressorOn::End() {
  log_debug("End()");
}

void CompressorOn::Interrupted() {
  log_debug("Interrupted()");
}
