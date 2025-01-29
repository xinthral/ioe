#ifndef LEXICON_H
#define LEXICON_H

#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include "config.h"
#include "logger.h"

/*!
 * @class   Lexicon lexicon.cpp lexicon.h
 * @brief   The Lexicon will handle ciphers, names, word generations and hold
 *          the names generated for lookup
*/
class Lexicon {
protected:
  ConfigManager*            cnf;        //!< ConfigManager Instantiation
  Logger*                   log;        //!< Logging Handler Instantiation
  std::string               lexigraph;  //!< Lexigraph for Language (symbols)
  std::vector<std::string>  syllables;  //!< Common Language Syllables

private:
  char                      buf[1024];  //!< Buffer Value for Logger outputs

public:
  /*!
   * @brief   Default Constructor
  */
  Lexicon();

  /*!
   * @brief   Generate A random Name based on Syllable count
   * @param[in] count - Number of Syllables in desired name
  */
  std::string generateName(int);

  /*!
   * @brief   Returns the current size of the Lexigraph
   * @return  Size of Current Lexigraph
  */
  int getLexigraphSize();

  /*!
   * @brief   Returns the current size of the Lexigraph
   * @return  Size of Current Lexigraph
  */
  void setLexigraph(std::string);

  void _help();

  /*!
   * @brief   Default Deconstructor
  */
  ~Lexicon();
};

#endif // LEXICON_H //