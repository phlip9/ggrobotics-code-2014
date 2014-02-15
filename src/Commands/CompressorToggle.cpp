#include "CompressorOn.h"

#include "../Robot.h"
#include "../Logging.h"

CompressorOn::CompressorOn(bool on)
  : Command("Compressor"),
    compressor_on(on){

  log_debug("Compressor()");

}

void CompressorOn::Initialize() {
  log_debug("Initialize()");
}

void CompressorOn::Execute() {
  if (compressor_on) {
    Robot::hardware_map()->compressor.Start();
  } else {
    Robot::hardware_map()->compressor.Stop();
  }
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
