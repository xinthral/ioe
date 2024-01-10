#include "battlehelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
HelpBattle::HelpBattle() { battlefield = new Battle(); battlefield->_help(); }

/*!
 * @todo    Default Deconstructor
*/
HelpBattle::~HelpBattle() { }