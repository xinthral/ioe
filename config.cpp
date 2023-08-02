#include "config.h"

/* Singleton Instance */
ConfigManager* ConfigManager::_singleton = NULL;
std::mutex ConfigManager::_mutex;

ConfigManager::ConfigManager() { 
    log = Logger::GetInstance();
    log->named_log(__FILE__, "ConfigManager Established.");
    load_config(false); 
}

ConfigManager* ConfigManager::GetInstance() {
    // Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    // If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new ConfigManager(); }
    return _singleton;
}

size_t ConfigManager::add_setting(const std::string& option, const std::string& value) {
    settings[option] = value;
    return settings.size();
}

size_t ConfigManager::rem_setting(const std::string& option) {
    settings.erase(option);
    return settings.size();
}

void ConfigManager::reload_state() {
    /* Forces a reload on the configuration file */
    this->load_config(true);
}

std::string ConfigManager::raw_config(const std::string& option) {
    /* Return the Value of a Configuration Option 
     * Param:
     *  <str|option> - The name of the Configuration Option
     * Return: <str|value>
     */
    return settings[option];
}

std::string ConfigManager::get_version() {
return this->raw_config("VERSION");
}

int ConfigManager::get_difficulty() {
    return atoi(this->raw_config("DIF").c_str());
}

int ConfigManager::get_attack() {
    return atoi(this->raw_config("ATK").c_str());
}

int ConfigManager::get_defense() {
    return atoi(this->raw_config("DEF").c_str());
}

int ConfigManager::get_health() {
    return atoi(this->raw_config("HLT").c_str());
}

bool ConfigManager::load_config(bool _debug) {
    /* Reads in Config File and Parses Options
     * Param:
     *  <bool|flag> - Debugging Option
     */
    std::size_t pos;                                // Positional Pointer for delimeter
    std::string row;                                // Temporary File Row Storage
    std::string opt;                                // Settings Option
    std::string val;                                // Settings Value
    std::size_t qsize;                              // Current Size of Queue
    int cnt = 0;
    conf.open("engine.ini");                        // Open INI file for reading
    while (std::getline(conf, row)) {
        // DEBUG Line
        if (_debug) { log->named_log(__FILE__, ("%d: %s\n", cnt++, row.c_str())); }
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

void ConfigManager::_help() { /* */ }

ConfigManager::~ConfigManager() {}