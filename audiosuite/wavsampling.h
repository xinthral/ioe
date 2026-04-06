#ifndef WAVSAMPLING_H
#define WAVSAMPLING_H

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../core/audio.h"
#include "../core/logger.h"
#include "wavdriver.h"
#include "mp3driver.h"
#include "flacdriver.h"

/*!
 * @class   WavSampler wavsampling.cpp wavsampling.h
 * @brief   needs desc
*/
class WavSampler {
protected:
private:
  Logger* log;
  AudioDriver* wavReader;
public:
  /*! @brief   Default Constructor */
  WavSampler();
  void sampleFile(const std::string&);
  void plotFrequencyChart(const std::vector<short>&, int);
  /*! @brief   Default Deconstructor */
  ~WavSampler();
};

#endif // WAVSAMPLING_H //