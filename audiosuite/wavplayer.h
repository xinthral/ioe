#ifndef WAVPLAYER_H
#define WAVPLAYER_H

#include <cstdlib>
#include <string>
#include "../core/config.h"
#include "../core/logger.h"

/*!
 * @class   WavPlayer wavplayer.cpp waveplayer.h
 * @brief   WavPlayer Class
*/
class WavPlayer {
protected:
  ConfigManager*  cnf;
  Logger*         log;
  char            buf[1024];
private:
public:
  /*! @brief   Default Constructor */
  WavPlayer();
  void playwav(const std::string&);
  /*! @brief   Default Deconstructor */
  ~WavPlayer();
};

#endif // WAVPLAYER_H //