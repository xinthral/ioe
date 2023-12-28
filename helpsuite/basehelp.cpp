/*!
 * @class   BaseHelp helpbase.h helpbase.cpp 
 * @brief   Base Class for the HelpSuite Module
*/

#include "basehelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
BaseHelp::BaseHelp() { }

/*!
 * @brief   Default Deconstructor
*/
BaseHelp::~BaseHelp() { }