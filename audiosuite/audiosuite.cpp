
#include "audiosuite.h"

/*!
 * @brief   Default constructor
*/
AudioMixer::AudioMixer() {
  log = Logger::GetInstance();
}

/*!
 * @brief   needs desc
*/
void AudioMixer::print_help() {
  std::string filename = Utilz::FileName(__FILE__);
  sprintf(buf, "Usage: %s.exe [option]\n", filename.c_str());
  log->raw_log(buf);
  log->raw_log("\n");
}

/*!
 * @brief   needs desc
*/
void AudioMixer::_help() {
  std::string helpline = "Mixer Help!";
  helpline += "\n";
  log->named_log(__FILE__, helpline);
}

/*!
 * @brief   Default Deconstructor
*/
AudioMixer::~AudioMixer() { }

int main(int argc, char const *argv[]) {
  // Logger* _log = Logger::GetInstance();
  AudioMixer* audio = new AudioMixer();
  WaveSampler* sampler = new WaveSampler();
  std::string input = "./audiosuite/samples/";
  if (argc < 2) { audio->print_help(); return 0; }
  if (argc > 1) { 
    if (strcmp(argv[1], "-h") == 0) { 
      audio->print_help();
      return 0; 
    }
    input += argv[1];
    input += ".wav"; 
  } else { input += "mixkit-retro-game-over.wav"; }
  sampler->sampleFile(input);
  // audio->print_help();
  return 0;
}