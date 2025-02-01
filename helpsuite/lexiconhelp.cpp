#include "lexiconhelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpLexicon::HelpLexicon() { 
  lexicon = new Lexicon();
  lexicon->_help(); 
}

/*!
 * @brief   Default Deconstructor
*/
HelpLexicon::~HelpLexicon() { }
