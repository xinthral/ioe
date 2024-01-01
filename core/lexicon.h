#ifndef LEXICON_H
#define LEXICON_H

#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include "config.h"
#include "logger.h"

class Lexicon {
protected:
  ConfigManager* cnf;
  Logger* log;
  std::string lexigraph;
  std::vector<std::string> syllables;
  char buf[1024];
private:
public:
  Lexicon();
  std::string generateName(int);
  int getLexigraphSize();
  void setLexigraph(std::string);
  ~Lexicon();
};

#endif // LEXICON_H //