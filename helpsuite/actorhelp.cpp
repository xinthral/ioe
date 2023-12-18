/*!
 * @class   ActorHelp helpactor.h helpactor.cpp
 * @brief   Command Line Tool (CLI) for Help
 * @details ActorHelp Callback for the HelpSuite 
*/

#include "actorhelp.h"

/*!
 * @brief   Default Constructor
*/
ActorHelp::ActorHelp() { dummy = new Actor(); dummy->_help(); }

/*!
 * @brief   Default Deconstructor
*/
ActorHelp::~ActorHelp() { }
