#include "helping.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
HelpHelping::HelpHelping() { }

/*!
 * @todo    Default Deconstructor
*/
HelpHelping::~HelpHelping() { }