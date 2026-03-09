#include "api.h"

std::string _FILENAME = "engine.exe";

APIEngine::APIEngine() {
  this->cnf = ConfigManager::GetInstance();
  this->log = Logger::GetInstance();
  this->start_time = std::chrono::steady_clock::now();
  this->prompt = ">";
}

void APIEngine::print_help() {
  //! Establish Logger Object
  Logger* log = Logger::GetInstance();

  //! Display Help 
  char buf[128];
  sprintf(buf, "\nUsage: %s [options]", _FILENAME.c_str()); 
  log->raw_log(buf);
  log->raw_log("\nOptions:");
  log->raw_log("\t-h, --help        Show Help Message");
  log->raw_log("\t-v, --version     Show Version Number");
#ifndef __linux__
  log->raw_log("[Note]: Must be ran on linux\n");
#endif

}


void APIEngine::print_version() {
  //! Establish Static Objects
  Logger* log = Logger::GetInstance();
  ConfigManager* cnf = ConfigManager::GetInstance();

  //! Get File Name
  std::string fileName = Utilz::FileName(__FILENAME__);
  std::string version = cnf->get_version();

  //! Display Version
  char buf[128];
  sprintf(buf, "\n%s version -> %s", _FILENAME.c_str(), version.c_str()); 
  log->raw_log(buf);
}

int main(int argc, char** argv) {
  //! Conditional Check
  if (argc < 1) { APIEngine::print_help(); return 0; }
  
#ifndef __WIN32
  //! Establish CLI Parameters
  int opt;
  static struct option long_options[] = {
    {"help",    no_argument,      0,  'h'},
    {"version", no_argument,      0,  'v'},
    {0, 0}
  };

  while ((opt = getopt_long(argc, argv, "hv", long_options, nullptr)) != -1) {
    switch (opt) {
      case 'h':
        APIEngine::print_help();
        return 0;
      case 'v':
        APIEngine::print_version();
        return 0;
      case '?':
        APIEngine::print_help();
        return 1;
    }
  }

  //! Handle Remaining Positional Arguments
  if (optind >= argc) {
    std::cerr << "Error: missing parameter\n";
    APIEngine::print_help();
    return 1;
  }

#elif __linux__
  APIEngine::print_help();
  return 0;
#endif
}
