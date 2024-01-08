#ifndef WAVSAMPLING_H
#define WAVSAMPLING_H

#include <string>
#include "../core/audio.h"
#include "../core/logger.h"

/*!
 * @class   WavSampler wavsampling.cpp wavsampling.h
 * @brief   needs desc
*/
class WavSampler {
protected:
private:
  Logger* log;
public:
  AudioDriver* wavReader;
  /*! @brief   Default Constructor */
  WavSampler();
  void sampleFile(const std::string&);
  /*! @brief   Default Deconstructor */
  ~WavSampler();
};

#endif // WAVSAMPLING_H //