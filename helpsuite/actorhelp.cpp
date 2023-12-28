/*!
 * @class   HelpActor helpactor.h helpactor.cpp
 * @brief   Additional details about the Actor class, it's implementation
 *          and any developers details relevant to it's use.
 * @details HelpActor Callback for the HelpSuite 
*/

#include "actorhelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpActor::HelpActor() { dummy = new Actor(); dummy->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpActor::~HelpActor() { }
