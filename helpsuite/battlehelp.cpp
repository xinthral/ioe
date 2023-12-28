/*!
 * @class   HelpBattle battlehelp.h battlehelp.cpp
 * @brief   Help details about the Battle module.
 * @details Includes features like how it works, hints
 *          working with the engine and more.
*/
#include "battlehelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpBattle::HelpBattle() { }

/*!
 * @brief   Default Deconstructor
*/
HelpBattle::~HelpBattle() { }