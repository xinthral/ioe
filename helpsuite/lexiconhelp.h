#ifndef HELPLEXICON_H
#define HELPLEXICON_H

#include "basehelp.h"

/*!
 * @class   HelpLexicon lexiconhelp.h lexiconhelp.cpp
 * @brief   Help details about the StageManager itself. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
class HelpLexicon : public BaseHelp {
protected:
private:
  Lexicon * lexicon;   //!< Placeholder Lexicon Object

public:
  /*!
   * @brief   Default Constructor
  */
  HelpLexicon();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpLexicon();
};

#endif // HELPLEXICON_H //
