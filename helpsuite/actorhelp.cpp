/*!
 * @class   ActorHelp helpactor.h helpactor.cpp
 * @brief   Command Line Tool (CLI) for Help
 * @details ActorHelp Callback for the HelpSuite 
*/

#include "actorhelp.h"

/*!
 * @brief   Default Constructor
*/
ActorHelp::ActorHelp() {
  Actor* dummy;
  dummy->_help(buf);
  BaseHelp::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
ActorHelp::~ActorHelp() { }
