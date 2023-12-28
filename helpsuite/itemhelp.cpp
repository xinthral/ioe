/*!
 * @class   HelpItem itemhelp.h itemhelp.cpp
 * @brief   Help details about the Base Item Module. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
#include "itemhelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpItem::HelpItem() { _item = new Item(); _item->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpItem::~HelpItem() { }