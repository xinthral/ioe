#include "config.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

//! Singleton Instance 
ConfigManager* ConfigManager::_singleton = NULL;
//! Lock Mutex
std::mutex ConfigManager::_mutex;

/*!
 * @todo    Protected Constructor 
*/
ConfigManager::ConfigManager() {

  log = Logger::GetInstance();
  log->named_log(__FILE__, "ConfigManager Established.");
  load_config(false); 
}

/*!
 * @todo    Singleton Constructor 
*/
ConfigManager* ConfigManager::GetInstance() {
  // Acquire Instance Mutex
  std::lock_guard<std::mutex> lock(_mutex);
  // If singleton already exists, return instance
  if (_singleton == NULL) { _singleton = new ConfigManager(); }
  return _singleton;
}

/*!
 * @todo    Reads in Config File and Parses Options
*/
bool ConfigManager::load_config(bool _debug) {
  char buf[64];
  std::size_t pos;                            //! Positional Pointer for delimeter
  std::string row;                            //! Temporary File Row Storage
  std::string opt;                            //! Settings Option
  std::string val;                            //! Settings Value
  std::size_t qsize = 0;                      //! Current Size of Queue
  int cnt = 0;
  conf.open("docs/engine.ini");               //! Open INI file for reading
  while (std::getline(conf, row)) {
    // DEBUG Line
    if (_debug) { 
      sprintf(buf, "%s", row.c_str()); 
      log->named_log(__FILENAME__, buf);
    }
    pos = row.find(delim);                    //! Locate Position of Delimiter
    if (pos != std::string::npos){
      opt = row.substr(0, pos);               //! Grab Option Name
      Utilz::Strip(opt);
      val = row.substr(pos+2, row.size()-1);  //! Grab Option Value
      qsize = this->add_setting(opt, val);    //! Load Setting
      cnt++;                                  //! Increment Settings counter
    }
  }
  conf.close();                               //! Close INI file descriptor
  return cnt == qsize;
}

/*!
 * @todo    Reload Settings
*/
void ConfigManager::reload_state() { this->load_config(true); }

/*!
 * @todo    Injest Setting into struct, and return struct size.
*/
size_t ConfigManager::add_setting(const std::string& option, const std::string& value) {
  this->settings[option] = value;
  return this->settings.size();
}

/*!
 * @todo    Remove Setting from injested list
*/
size_t ConfigManager::rem_setting(const std::string& option) {
  this->settings.erase(option);
  return this->settings.size();
}

/*!
 * @todo    Return the Value of a Configuration Option 
*/
std::string ConfigManager::raw_config(const std::string& option) {
  return this->settings[option];
}

/*!
 * @todo    Return the list of authorized commands for the CLI Suite
*/
void ConfigManager::get_authorizedCommands(std::vector<std::string>& input) { 
  std::string inp = this->raw_config("CMDLIST");
  Utilz::StringToArray(inp, input);
}

/*!
 * @todo    Helper Function: Attack 
*/
int ConfigManager::get_attack() { return atoi(this->raw_config("ATK").c_str()); }

/*!
 * @todo    Helper Function: Base Scalar
*/
int ConfigManager::get_base() { return atoi(this->raw_config("BAS").c_str()); }

/*!
 * @todo    Helper Function: Defense 
*/
int ConfigManager::get_defense() { return atoi(this->raw_config("DEF").c_str()); }

/*!
 * @todo    Helper Function: Difficulty
*/
int ConfigManager::get_difficulty() { return atoi(this->raw_config("DIF").c_str()); }

/*!
 * @todo    Helper Function: Flux 
 */
int ConfigManager::get_flux() { return atoi(this->raw_config("FLX").c_str()); }

/*!
 * @todo    Helper Function: Health
*/
int ConfigManager::get_health() { return atoi(this->raw_config("HLT").c_str()); }

/*!
 * @todo    Helper Function: Settings 
*/
size_t ConfigManager::get_settingsSize() { return this->settings.size(); }

/*!
 * @todo    Helper Function: Version
*/
std::string ConfigManager::get_version() { return this->raw_config("VERSION"); }

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void ConfigManager::_help() {
  std::string helpline = "\nConfigManager Helpline!\n";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor
*/
ConfigManager::~ConfigManager() { }
