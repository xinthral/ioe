#include "playerhelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
HelpPlayer::HelpPlayer() { ptest = new Player("HelpPlayer", 1); ptest->_help(); }

/*!
 * @todo    Default Deconstructor
*/
HelpPlayer::~HelpPlayer() { }
