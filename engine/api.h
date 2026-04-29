#ifndef XAPI_H
#define XAPI_H

#include <chrono>
#include <stdio.h>
#include <string.h>
#include "../core/config.h"
#include "../core/logger.h"

/*!
 * @class   APIEngine api.h api.cpp
 * @brief   Entry-point wrapper; parses CLI args and starts WorldServer.
*/
class APIEngine {
private:
  ConfigManager *cnf;
  Logger        *log;
  std::chrono::time_point<std::chrono::steady_clock> start_time;
public:
  APIEngine();
  static void print_help();
  static void print_version();
};

#endif // XAPI_H //
