/*!
 * @class   HelpItem itemhelp.h itemhelp.cpp
 * @brief   Help details about the Base Item Module. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
#include "itemhelp.h"

/*!
 * @brief   Default Constructor
*/
HelpItem::HelpItem() { _item = new Item(); _item->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpItem::~HelpItem() { }