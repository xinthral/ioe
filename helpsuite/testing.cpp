/*!
 * @class   HelpTesting testing.h testing.cpp
 * @brief   Help details about TestSuite Features of Engine 
 * @details Help details about the testing system used 
 *          to perform unit testing and it's functionality.
*/
#include "testing.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpTesting::HelpTesting() { }

/*!
 * @brief   Default Deconstructor
*/
HelpTesting::~HelpTesting() { }