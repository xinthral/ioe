/*!
 * @class   HelpToon toonhelp.h toonhelp.cpp
 * @brief   Help details about the Toon module. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
#include "toonhelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpToon::HelpToon() { }

/*!
 * @brief   Default Deconstructor
*/
HelpToon::~HelpToon() { }