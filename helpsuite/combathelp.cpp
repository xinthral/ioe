#include "combathelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
HelpCombat::HelpCombat() { cc = new Combat(); cc->_help(); }

/*!
 * @todo    Default Deconstructor
*/
HelpCombat::~HelpCombat() { }