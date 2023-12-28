/*!
 * @class   HelpAudio audiohelp.h audiohelp.cpp
 * @brief   Help details about the Audio module. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
#include "audiohelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpAudio::HelpAudio() { }

/*!
 * @brief   Default Deconstructor
*/
HelpAudio::~HelpAudio() { }

