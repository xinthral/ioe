#include "leaderhelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpLeader::HelpLeader() { }

/*!
 * @brief   Default Deconstructor
*/
HelpLeader::~HelpLeader() { }
