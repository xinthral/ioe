#ifndef STAGE_H
#define STAGE_H

#include <mutex>
#include <stdio.h>
#include <string>
#include <vector>
#include "logger.h"
#include "toon.h"

class StageManager {
protected:
  StageManager(const std::string);
private:
  static StageManager* _singleton;
  static std::mutex _mutex;
  Logger* log;
  std::string name;
  int maxCrew = 10;
  char buf[128];
public:
  StageManager(StageManager&) = delete;                   //!< Singletons should not be cloneable
  void operator = (const StageManager&) = delete;         //!< Singletons should not be assignable
  static StageManager *GetInstance(const std::string&);   //!< Singleton Constructor
  std::string get_name();
  void casting_call(int, std::vector<Toon*>&);
  void _help();
  ~StageManager();
};

#endif // STAGE_H //
