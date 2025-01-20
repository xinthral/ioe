#include "clockhelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpClock::HelpClock() { 
  clock = xClock::GetInstance();
  clock->_help(); 
}

/*!
 * @brief   Default Deconstructor
*/
HelpClock::~HelpClock() { }
