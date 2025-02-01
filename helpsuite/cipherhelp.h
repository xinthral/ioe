#ifndef HELPCIPHER_H
#define HELPCIPHER_H

#include "basehelp.h"

/*!
 * @class   HelpCipher clockhelp.h clockhelp.cpp
 * @brief   Help details about the StageManager itself. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
class HelpCipher : public BaseHelp {
protected:
private:
  xCiphers * cipher;   //!< Placeholder Cipher Object

public:
  /*!
   * @brief   Default Constructor
  */
  HelpCipher();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpCipher();
};

#endif // HELPCIPHER_H //
