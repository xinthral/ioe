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
#ifdef __linux__
  log->raw_log("[Note]: Linux Specific Instructions\n");
#elifdef __WIN32
  log->raw_log("[Note]: Windows Specific Instructions\n");
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


void APIEngine::process_instructions(int argc, char** argv) {

  //! Iterate over command-line arguments
  for (int i = 1; i < argc; i++) {
    printf("Instruction #%d: %s\n", i, argv[i]);
  }

  //! Add More here
  
}


int main(int argc, char** argv) {
  //! Conditional Check
  if (argc < 1) { APIEngine::print_help(); return 0; }
  
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
      case 'v':
        APIEngine::print_version();
      case '?':
        APIEngine::print_help(); return 1;
    }
  }

  //! Handle Remaining Positional Arguments
  if (optind >= argc) {
    std::cerr << "Error: missing parameter\n";
    APIEngine::print_help();
    return 1;
  }

  APIEngine::process_instructions(argc, argv);
  return 0;
}
