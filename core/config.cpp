/*!
 * @class   ConfigManager config.h config.cpp
 * @brief   ConfigManager Docstring
 */
#include "config.h"

//! Singleton Instance 
ConfigManager* ConfigManager::_singleton = NULL;
std::mutex ConfigManager::_mutex;

/*!
 * @brief   Protected Constructor 
*/
ConfigManager::ConfigManager() { 
    log = Logger::GetInstance();
    log->named_log(__FILE__, "ConfigManager Established.");
    load_config(false); 
}

/*!
 * @brief   Singleton Constructor 
*/
ConfigManager* ConfigManager::GetInstance() {
    // Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    // If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new ConfigManager(); }
    return _singleton;
}

/*!
 * @brief   Injest Setting into struct, and return struct size.
 * @param[in] option - The Key value for lookup
 * @param[in] value  - The data value associated with the key
 * @return  Returns current config queue size 
*/
size_t ConfigManager::add_setting(const std::string& option, const std::string& value) {
  this->settings[option] = value;
  return this->settings.size();
}

/*!
 * @brief   Remove Setting from injested list
 * @param[in] option - The name of the Configuration Option 
 * @return  Current Size of Settings List
*/
size_t ConfigManager::rem_setting(const std::string& option) {
  this->settings.erase(option);
  return this->settings.size();
}

/*!
 * @brief   Reload Settings
 * @details Forces a reload of the injested settings list,
 *          and outputs the configs to the logs.
*/
void ConfigManager::reload_state() { this->load_config(true); }

/*!
 * @brief   Return the Value of a Configuration Option 
 * @param[in] option - The name of the Configuration Option
 * @return  The value related to input key
 */
std::string ConfigManager::raw_config(const std::string& option) { return this->settings[option]; }

/*!
 * @brief   Return the list of authorized commands for the 
 *          CLI Suite
 * @param[out] option - A string array to recieve the commands
*/
void ConfigManager::get_authorized_cli_commands(std::vector<std::string>& input) { 
  std::string inp = "exit help "; 
  inp += this->raw_config("CMDLIST");
  Utilz::StringToArray(inp, &input);
}

/*!
 * @brief   Helper Function: Attack 
 * @return  Return base attack value 
 */
int ConfigManager::get_attack() { return atoi(this->raw_config("ATK").c_str()); }

/*!
 * @brief   Helper Function: Base Scalar
 * @return  Return base scalar value 
*/
int ConfigManager::get_base() { return atoi(this->raw_config("BAS").c_str()); }

/*!
 * @brief   Helper Function: Defense 
 * @return  Return base defense value 
 */
int ConfigManager::get_defense() { return atoi(this->raw_config("DEF").c_str()); }

/*!
 * @brief   Helper Function: Difficulty
 * @return  Return base difficulty value
*/
int ConfigManager::get_difficulty() { return atoi(this->raw_config("DIF").c_str()); }

/*!
 * @brief   Helper Function: Flux 
 * @return  Return base flux value 
 */
int ConfigManager::get_flux() { return atoi(this->raw_config("FLX").c_str()); }

/*!
 * @brief   Helper Function: Health
 * @return  Return base health value 
 */
int ConfigManager::get_health() { return atoi(this->raw_config("HLT").c_str()); }

/*!
 * @brief   Helper Function: Settings 
 * @return  Return size of settings vector 
 */
size_t ConfigManager::get_settingsSize() { return this->settings.size(); }

/*!
 * @brief   Helper Function: Version
 * @return  Return game version
*/
std::string ConfigManager::get_version() { return this->raw_config("VERSION"); }

/*!
 * @brief   Reads in Config File and Parses Options
 * @param[in] _debug - Debugging Option
 * @return  Confirmation that all values were loaded
 */
bool ConfigManager::load_config(bool _debug) {
  char buf[64];
  std::size_t pos;                                //! Positional Pointer for delimeter
  std::string row;                                //! Temporary File Row Storage
  std::string opt;                                //! Settings Option
  std::string val;                                //! Settings Value
  std::size_t qsize = 0;                          //! Current Size of Queue
  int cnt = 0;
  conf.open("docs/engine.ini");                   //! Open INI file for reading
  while (std::getline(conf, row)) {
    // DEBUG Line
    if (_debug) { 
      sprintf(buf, "%d: %s\n", cnt++, row.c_str()); 
      log->named_log(__FILE__, buf);
    }
    pos = row.find(delim);                      //! Locate Position of Delimiter
    if (pos != std::string::npos){
      opt = row.substr(0, pos);               //! Grab Option Name
      Utilz::Strip(opt);
      val = row.substr(pos+1, row.size()-1);  //! Grab Option Value
      Utilz::Strip(val);
      qsize = this->add_setting(opt, val);    //! Load Setting
      cnt++;                                  //! Increment Settings counter
    }
  }
  conf.close();                                   //! Close INI file descriptor
  return cnt == qsize;
}

/*!
 * @brief   Helper Hook used in CLI Help System
*/
void ConfigManager::_help() { }

ConfigManager::~ConfigManager() {}