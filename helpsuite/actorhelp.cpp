/*!
 * @class   HelpActor helpactor.h helpactor.cpp
 * @brief   Additional details about the Actor class, it's implementation
 *          and any developers details relevant to it's use.
 * @details HelpActor Callback for the HelpSuite 
*/

#include "actorhelp.h"

/*!
 * @brief   Default Constructor
*/
HelpActor::HelpActor() { dummy = new Actor(); dummy->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpActor::~HelpActor() { }
