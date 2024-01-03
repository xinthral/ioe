/*!
 * @class   xCiphers ciphers.cpp ciphers.h
 * @brief   The cipher suite will handle logical lexiconal shifting
 *          and word translations
*/
#include "ciphers.h"

/*!
 * @brief   Default Constructor
*/
xCiphers::xCiphers() {
  this->rows =lexigraph.size();
  this->cols =lexigraph.size();
  this->keySize = (int)sizeof(keyArray) / sizeof(keyArray[0]);
}

/*!
 * @brief   Overloaded Constructor
 * @param[in] code - Character to start the cipher
 * @param[in] key  - Salt for the cipher
*/
xCiphers::xCiphers(char code, std::string key) : xCiphers() {
  this->keyArray = key.c_str();
  this->generateMatrix(code);
}

/*!
 * @brief   Locates the index of the given letter in the lexigraph 
 * @param[in] letter - Character to be looked up
*/
int xCiphers::getIndex(char letter) {
  for (int i = 0; i < Lexicon::getLexigraphSize(); i++) {
    if (Lexicon::lexigraph[i] == letter) { return i; }
  }
  return 0;
}

/*!
 * @brief   Generates an N x N matrix where N := Number of elements
 *          in the lexigraph.
*/
void xCiphers::generateMatrix(char code) {
  int startIdx = getIndex(code);
  int diff = 0;
  int lexSize = Lexicon::getLexigraphSize();
  std::string shifted;
  for (int i = 0; i < lexSize; i++) {
    shifted = "";
    diff = lexSize - startIdx;
    shifted = Lexicon::lexigraph.substr(startIdx, diff);
    shifted += Lexicon::lexigraph.substr(0, startIdx);
    outputMatrix.push_back(shifted);
    shadowMatrix.push_back(shifted);
    if (startIdx < lexSize) { startIdx++; }
    else { startIdx = 0; }
  }
}

/*!
 * @brief   Gets the size of the matrix
 * @return  Size of the matrix
*/
int xCiphers::getMatrixSize() { return outputMatrix.size(); }

/*!
 * @brief   
*/
std::string xCiphers::encode(std::string input) {
  std::string output = "";
  int keyIdx = 0;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] != ' ') {
      int firstIdx = getIndex(keyArray[keyIdx]);
      int secondIdx = getIndex(input[i]);
      output += outputMatrix[firstIdx][secondIdx];
      shadowMatrix[firstIdx][secondIdx] = input[i];
    } else { output += " "; }
    if (keyIdx < input.size() - 1) { keyIdx++; }
    else { keyIdx = 0; }
  }
  return output;
}

/*!
 * @brief   
*/
std::string xCiphers::decode(std::string input) {
  std::string output = "";
  int keyIdx = 0;
  for(int i = 0; i < input.size(); i++) { 
    if (input[i] != ' ') {
      std::string tmp = outputMatrix[getIndex(keyArray[keyIdx])];
      for (int j = 0; j < tmp.size(); j++) {
        if (tmp[j] == input[i]) { output += lexigraph[j]; }
      }
    } else { output += " "; }
    if (keyIdx < input.size() - 1) { keyIdx++; }
    else { keyIdx = 0; }
  }
  return output;
}

/*!
 * @brief   
*/
void xCiphers::displayMatrix(bool blackOut) {
  std::string matrixStr = "";
  std::string shadowStr = "";
  std::string header = "[ ] ";
  std::string tbuf = "";
  int lexSize = Lexicon::getLexigraphSize();
  char tchar[1024];
  for (int i = 0; i < lexSize; i++) {
    sprintf(tchar, "[%s]", lexigraph[i]);
    tbuf = tchar;
    matrixStr += tbuf;
    shadowStr += tbuf;
    int tsize = outputMatrix[i].size();
    for (int j = 0; j < tsize; j++) {
      sprintf(tchar, " | %s", outputMatrix[i][j]);
      tbuf = tchar;
      matrixStr += tbuf; 
      shadowStr += tbuf; 
    }
  }

  for (int k = 0; k < lexSize; k++) {
    sprintf(tchar, "[%c] ", lexigraph[k]);
    tbuf = tchar;
    header += tbuf;
    printf("%s\n", header);
    log->raw_log(header);
  }

  printf("%s\n", header);
  log->raw_log(header);

  for (int l = 0; l < matrixStr.size(); l++) { 
    sprintf(tchar, "%c", blackOut ? shadowStr[l] : matrixStr[l]);
    tbuf = tchar;
    printf("%s\n", header);
    log->raw_log(tbuf);
  }
}

/*!
 * @brief   Default Deconstructor
*/
xCiphers::~xCiphers() { }
