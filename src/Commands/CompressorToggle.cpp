#include "CompressorToggle.h"

#include "../Robot.h"
#include "../Logging.h"

CompressorToggle::CompressorToggle(bool on)
  : Command("CompressorToggle"),
    compressor_on(on){

  log_debug("Compressor()");

}

void CompressorToggle::Initialize() {
  log_debug("Initialize()");
}

void CompressorToggle::Execute() {
  if (compressor_on) {
    Robot::hardware_map()->compressor.Start();
  } else {
    Robot::hardware_map()->compressor.Stop();
  }
}

bool CompressorToggle::IsFinished() {
  return true;
}

void CompressorToggle::End() {
  log_debug("End()");
}

void CompressorToggle::Interrupted() {
  log_debug("Interrupted()");
}
