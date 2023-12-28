/*!
 * @class   HelpUtilz utilzhelp.h utilzhelp.cpp
 * @brief   Help details about the Utilz module. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
#include "utilzhelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpUtilz::HelpUtilz() { }

/*!
 * @brief   Default Deconstructor
*/
HelpUtilz::~HelpUtilz() { }
