#include "itemhelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
HelpItem::HelpItem() { _item = new Item(); _item->_help(); }

/*!
 * @todo    Default Deconstructor
*/
HelpItem::~HelpItem() { }
