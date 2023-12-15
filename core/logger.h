#ifndef XLOGGER_H
#define XLOGGER_H

#include <stdio.h>
#include <mutex>
#include <string>
#include <unordered_map>
#include "utilz.h"

class Logger {
protected:
  Logger();
private:
  std::unordered_map<std::string, std::string> settings;
  static const std::string DELIM;
  static Logger* _singleton;
  static std::mutex _mutex;
  char buf[1024];

public:
  Logger(Logger&) = delete;                   //! Singletons should not be cloneable
  void operator =(const Logger&) = delete;    //! Singletons should not be assignable
  static Logger* GetInstance();               //! Singleton Constructor
  void raw_log(std::string);
  void timed_log(std::string);
  void named_log(std::string, std::string); 
  void _help();
  ~Logger();
};


#endif // XLOGGER_H //
