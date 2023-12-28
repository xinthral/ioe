/*!
 * @class   HelpConfig confighelp.h confighelp.cpp
 * @brief   Help details about the ConfigManager itself. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
#include "confighelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpConfig::HelpConfig() { _cnf = ConfigManager::GetInstance(); _cnf->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpConfig::~HelpConfig() { }