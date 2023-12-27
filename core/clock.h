#ifndef XCLOCK_H
#define XCLOCK_H

#include <mutex>
#include "balance.h"
#include "config.h"

class xClock {
protected:
  xClock();
  static xClock* _singleton;
  static std::mutex _mutex;

private:
  char            buf[256];
  ConfigManager*  cnf;
  Logger*         log;
public:
  xClock(xClock&) = delete;
  void operator = (const xClock&) = delete;
  static xClock* GetInstance();
  void _help();
  ~xClock();
};

#endif // XCLOCK_H //