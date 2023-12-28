/*!
 * @class   HelpHelping helping.h helping.cpp
 * @brief   Help details about the HelpSuite itself. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
#include "helping.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpHelping::HelpHelping() { }

/*!
 * @brief   Default Deconstructor
*/
HelpHelping::~HelpHelping() { }