#ifndef MIXER_H
#define MIXER_H

#include <string>
#include "../core/audio.h"
#include "../core/config.h"
#include "../core/logger.h"
#include "../core/utilz.h"
#include "../testsuite/profiler.h"
#include "wavsampling.h"
#include "wavplayer.h"

/*!
 * @class   AudioMixer audiosuite.cpp audiosuite.h
 * @brief   needs desc
*/
class AudioMixer {
protected:
  ConfigManager*  cnf;        //!< ConfigManager Instantiation
  Logger*         log;        //!< Logging Handler Instantiation
  char            buf[128];   //!< Buffer Space Reservation
private:
public:
  /*! @brief   Default constructor */
  AudioMixer();

  /*! @brief   Help details for the CLI Audio System */
  void print_help();

  /*! @brief   Helper Hook used in CLI Help System */
  void _help();

  /*! @brief   Default Deconstructor */
  ~AudioMixer();
};

#endif // MIXER_H //
