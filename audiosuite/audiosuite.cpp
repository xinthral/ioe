#include "audiosuite.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default constructor for the AudioMixer class.
 *
 * @details Initializes the Logger instance for use within the class.
*/
AudioMixer::AudioMixer() {
  log = Logger::GetInstance();
}

/*!
 * @brief   Prints the usage details for the AudioMixer class.
 *
 * @details This function displays the command-line usage details for the AudioMixer class.
 *          It includes the name of the executable, the available options, and their descriptions.
*/
void AudioMixer::print_help() {
  std::string filename = Utilz::FileName(__FILENAME__);
  sprintf(buf, "Usage: %s.exe [option]\n", filename.c_str());
  log->raw_log(buf);
  log->raw_log("  [-h]        - displays help details");
  log->raw_log("  [filename]  - Name of WAV file");
  log->raw_log("\n");
}

/*!
 * @brief   Helper Hook used in CLI Help System
*/
void AudioMixer::_help() {
  std::string helpline = "Mixer Help!";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*! @todo    Default Deconstructor */
AudioMixer::~AudioMixer() {}

int main(int argc, char const *argv[]) {
  // Logger* _log = Logger::GetInstance();
  AudioMixer* audio = new AudioMixer();
  WavSampler* sampler = new WavSampler();
  WavPlayer* player = new WavPlayer();

  std::string input = "./audiosuite/samples/";
  if (argc < 2) { audio->print_help(); return 0; }
  if (argc > 1) { 
    if (strcmp(argv[1], "-h") == 0) { 
      audio->print_help();
      return 0; 
    }
    input += argv[1];
    input += ".wav"; 
  } else { input += "game-over.wav"; }
  player->playwav(input);
  sampler->sampleFile(input);
  return 0;
}
