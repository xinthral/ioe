/*!
 * @class   HelpCombat combathelp.h combathelp.cpp
 * @brief   Help details about the Combat module. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
#include "combathelp.h"

/*!
 * @brief   Default Constructor
*/
HelpCombat::HelpCombat() { cc = new Combat(); cc->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpCombat::~HelpCombat() { }