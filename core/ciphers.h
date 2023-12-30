#ifndef XCIPHERS_H
#define XCIPHERS_H

#include "lexicon.h"

class xCiphers : public Lexicon {
protected:
  std::vector<std::string> shadowMatrix;
  std::vector<std::string> outputMatrix;
  const char *keyArray;
  int rows;
  int cols;
  int keySize;
private:
  int getIndex(char);
public:
  xCiphers();
  xCiphers(char,std::string);
  void generateMatrix(char);
  int getMatrixSize();
  std::string encode(std::string);
  std::string decode(std::string);
  void displayMatrix(bool);
  ~xCiphers();
};

#endif // XCIPHERS_H //