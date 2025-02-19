#include "cipherhelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpCipher::HelpCipher() { 
  cipher = new xCiphers();
  cipher->_help(); 
}

/*!
 * @brief   Default Deconstructor
*/
HelpCipher::~HelpCipher() { }
