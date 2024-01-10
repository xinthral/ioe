#include "basehelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
BaseHelp::BaseHelp() { }

/*!
 * @todo    Default Deconstructor
*/
BaseHelp::~BaseHelp() { }