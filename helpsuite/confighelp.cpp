/*!
 * @class   HelpConfig confighelp.h confighelp.cpp
 * @brief   Help details about the ConfigManager itself. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
#include "confighelp.h"

/*!
 * @brief   Default Constructor
*/
HelpConfig::HelpConfig() { _cnf = ConfigManager::GetInstance(); _cnf->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpConfig::~HelpConfig() { }