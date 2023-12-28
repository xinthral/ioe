/*!
 * @class   HelpCombat combathelp.h combathelp.cpp
 * @brief   Help details about the Combat module. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
#include "combathelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpCombat::HelpCombat() { cc = new Combat(); cc->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpCombat::~HelpCombat() { }