/*!
 * @class   WavPlayer wavplayer.cpp waveplayer.h
 * @brief   WavPlayer Class
*/
#include "wavplayer.h"
#include <cstdlib>

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
WavPlayer::WavPlayer() {
  log = Logger::GetInstance();
  cnf = ConfigManager::GetInstance();
  sprintf(buf, "WavPlayer Loaded!");
  log->named_log(__FILENAME__, buf);
}

void WavPlayer::playwav(const std::string& inFile) {
  // Replace "your_sound_file.wav" with the actual path to your sound file
  const char* soundFile = ("C:\\Users\\PC\\GitHub\\ioe\\" + inFile).c_str(); 

  // Build the aplay command
  std::string command = cnf->raw_config("VLCPATH") + " --qt-start-minimized --play-and-exit " + std::string(soundFile);

  // Call aplay using the system command
  int result = std::system(command.c_str());

  // Check the result
  if (result == 0) { sprintf(buf, "WavFile executed successfully."); } 
  else { sprintf(buf, "Error executing WavFile: %s.", command.c_str()); }
  log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
WavPlayer::~WavPlayer() { }