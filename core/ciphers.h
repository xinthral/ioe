#ifndef XCIPHERS_H
#define XCIPHERS_H

#include "lexicon.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @class   xCiphers ciphers.cpp ciphers.h
 * @brief   The cipher suite will handle logical lexiconal shifting
 *          and word translations
*/
class xCiphers : public Lexicon {
protected:
  /*!
   * @brief   Locates the index of the given letter in the lexigraph 
   * @param[in] letter - Character to be looked up
  */
  int getIndex(char);
private:
  std::vector<std::string> shadowMatrix;
  std::vector<std::string> outputMatrix;
  const char *keyArray;
  int rows;
  int cols;
  int keySize;
public:
  /*!
   * @brief   Default Constructor
  */
  xCiphers();

  /*!
   * @brief   Overloaded Constructor
   * @param[in] code - Character to start the cipher
   * @param[in] key  - Salt for the cipher
  */
  xCiphers(char,std::string);

  /*!
   * @brief   Generates an N x N matrix where N := Number of elements
   *          in the lexigraph.
  */
  void generateMatrix(char);

  /*!
   * @brief   Gets the size of the matrix
   * @return  Size of the matrix
  */
  int getMatrixSize();
  std::string encode(std::string);
  std::string decode(std::string);
  void displayMatrix(bool);
  void _help();
  /*!
   * @brief   Default Deconstructor
  */
  ~xCiphers();
};

#endif // XCIPHERS_H //