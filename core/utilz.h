#ifndef UTILZ_H
#define UTILZ_H

#include <algorithm>
#include <ctime>
#include <iterator>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "logger.h"

namespace Utilz {
  std::string FileName(const char *);
  std::string FileName(int, const char *);
  std::string TimeStamp();
  void StringToArray(std::string, std::vector<std::string>&);
  std::string HeadString(int, std::string);
  std::string TailString(int, std::string);
  void Strip(std::string&);
  void _help();
} // namespace Utilz

extern "C" {
  int addIt(int, int);
}

#endif // UTILZ_H //
