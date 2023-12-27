#ifndef MIXER_H
#define MIXER_H

#include <string>
#include "../core/audio.h"
#include "../core/config.h"
#include "../core/logger.h"
#include "../core/utilz.h"
#include "wavsampling.h"

class AudioMixer {
protected:
  ConfigManager*  cnf;
  Logger*         log;
  char            buf[1024];
private:
public:
  AudioMixer();
  void print_help();
  void _help();
  ~AudioMixer();
};

#endif // MIXER_H //
