#include "api.h"
#include "server.h"

#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

APIEngine::APIEngine() {
  this->cnf = ConfigManager::GetInstance();
  this->log = Logger::GetInstance();
  this->start_time = std::chrono::steady_clock::now();
}

void APIEngine::print_help() {
  Logger* log = Logger::GetInstance();
  log->raw_log("\nUsage: engine.exe [port]");
  log->raw_log("  port    - TCP port to listen on (default: 8080)");
  log->raw_log("  -h      - Show this help\n");
}

void APIEngine::print_version() {
  Logger* log = Logger::GetInstance();
  ConfigManager* cnf = ConfigManager::GetInstance();
  char buf[64];
  snprintf(buf, sizeof(buf), "engine version -> %s", cnf->get_version().c_str());
  log->raw_log(buf);
}

int main(int argc, char** argv) {
  if (argc >= 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
    APIEngine::print_help();
    return 0;
  }
  if (argc >= 2 && (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)) {
    APIEngine::print_version();
    return 0;
  }

  int port = 8080;
  if (argc >= 2) { port = atoi(argv[1]); }
  if (port <= 0 || port > 65535) {
    fprintf(stderr, "Error: invalid port '%s'\n", argv[1]);
    return 1;
  }

  WorldServer server("0.0.0.0", port);
  server.listen();
  return 0;
}
