#ifndef WAVPLAYER_H
#define WAVPLAYER_H

#include <cstdlib>
#include <string>
#include "../core/config.h"
#include "../core/logger.h"

class WavPlayer {
protected:
  ConfigManager*  cnf;
  Logger*         log;
  char            buf[1024];
private:
public:
  WavPlayer();
  void playwav(const std::string&);
  ~WavPlayer();
};

#endif // WAVPLAYER_H //