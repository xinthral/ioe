/*! \class ConfigManager config.h config.h
 * ConfigManager Docstring
 */
#include "config.h"

/* Singleton Instance */
ConfigManager* ConfigManager::_singleton = NULL;
std::mutex ConfigManager::_mutex;

/**
 * Protected Constructor 
*/
ConfigManager::ConfigManager() { 
    log = Logger::GetInstance();
    log->named_log(__FILE__, "ConfigManager Established.");
    load_config(false); 
}

/**
 * Singleton Constructor 
*/
ConfigManager* ConfigManager::GetInstance() {
    // Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    // If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new ConfigManager(); }
    return _singleton;
}

/**
 * Injest Setting into struct, and return struct size.
 * @param :<str|option> - The Key value for lookup
 * @param :<str|value> - The data value associated with the key
 * @return :<int|size>
*/
size_t ConfigManager::add_setting(const std::string& option, const std::string& value) {
    settings[option] = value;
    return settings.size();
}

/**
 * FIXME
*/
size_t ConfigManager::rem_setting(const std::string& option) {
    settings.erase(option);
    return settings.size();
}

/**
 * FIXME
*/
void ConfigManager::reload_state() {
    /* Forces a reload on the configuration file */
    this->load_config(true);
}

/**
 * Return the Value of a Configuration Option 
 * @param :<str|option> - The name of the Configuration Option
 * @return :<str|value> - The value related to input key
 */
std::string ConfigManager::raw_config(const std::string& option) {
    return settings[option];
}

/**
 * FIXME
*/
std::string ConfigManager::get_version() {
return this->raw_config("VERSION");
}

/**
 * FIXME
*/
int ConfigManager::get_base() {
    return atoi(this->raw_config("BAS").c_str());
}

/**
 * Helper Function: Attack 
 * @return :<int|value> - Return base attack value 
 */
int ConfigManager::get_attack() {
    return atoi(this->raw_config("ATK").c_str());
}

/**
 * Helper Function: Defense 
 * @return :<int|value> - Return base defense value 
 */
int ConfigManager::get_defense() {
    return atoi(this->raw_config("DEF").c_str());
}

/**
 * Helper Function: Difficulty
 * @return :<int|value> - Return base difficulty value
*/
int ConfigManager::get_difficulty() {
    return atoi(this->raw_config("DIF").c_str());
}

/**
 * Helper Function: Health
 * @return :<int|value> - Return base health value 
 */
int ConfigManager::get_health() {
    return atoi(this->raw_config("HLT").c_str());
}

/**
 * Reads in Config File and Parses Options
 * @param :<bool|flag> - Debugging Option
 * @return :<bool|value> - confirming count
 */
bool ConfigManager::load_config(bool _debug) {
    char* buf;
    std::size_t pos;                                // Positional Pointer for delimeter
    std::string row;                                // Temporary File Row Storage
    std::string opt;                                // Settings Option
    std::string val;                                // Settings Value
    std::size_t qsize = 0;                          // Current Size of Queue
    int cnt = 0;
    conf.open("docs/engine.ini");                   // Open INI file for reading
    while (std::getline(conf, row)) {
        // DEBUG Line
        if (_debug) { 
            sprintf(buf, "%d: %s\n", cnt++, row.c_str()); 
            log->named_log(__FILE__, buf);
        }
        pos = row.find(delim);                      // Locate Delimiter
        if (pos != std::string::npos){
            opt = row.substr(0, pos);               // Grab Option Name
            Utilz::Strip(opt);
            val = row.substr(pos+1, row.size()-1);  // Grab Option Value
            Utilz::Strip(val);
            qsize = this->add_setting(opt, val);    // Load Setting
            cnt++;                                  // Increment Settings counter
        }
    }
    conf.close();                                   // Close INI file descriptor
    return cnt == qsize;
}

/**
 * Helper Hook used in CLI Help System
*/
void ConfigManager::_help() { }

ConfigManager::~ConfigManager() {}