/*!
 * @class   TestCiphers leadercase.cpp leadercase.h
 * @brief   Test for the TestCiphers
*/

#include "cipherscase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
TestCiphers::TestCiphers() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the Ciphers!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "in the cipher suite!");
  cipher = new xCiphers('H', "BABBAGE");
  this->decoded = "HAPPY BIRTHDAY";
  this->encoded = "PHXXF MPYAOKHF";
  this->test_all();
}

/*!
 * @brief   Run full set of test on module 
*/
void TestCiphers::test_all() {
  this->generateMatrix();
  this->encode();
  this->decode();
  // this->displayMatrix(); // FIXME
}

/*!
 * @brief   
*/
void TestCiphers::displayMatrix() {
  cipher->displayMatrix(false);
  sprintf(buf, "%s [%s] %s", msgHead, "matrix display", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   
*/
void TestCiphers::decode() {
  std::string response = cipher->decode(encoded);
  sprintf(buf, "Decoding failed to produce %s: %s => %s", this->decoded.c_str(), this->encoded.c_str(), response.c_str());
  assertm(strcmp(response.c_str(), this->decoded.c_str()) == 0, buf);
  sprintf(buf, "%s [%s] %s (%s)", msgHead, "decoding", msgTail, response.c_str());
  BaseCase::log->named_log(__FILENAME__, buf);

}

/*!
 * @brief   
*/
void TestCiphers::encode() {
  std::string response = cipher->encode(decoded);
  sprintf(buf, "Encoding failed to produce %s: %s => %s", this->encoded.c_str(), this->decoded.c_str(), response.c_str());
  assertm(strcmp(response.c_str(), this->encoded.c_str()) == 0, buf);
  sprintf(buf, "%s [%s] %s (%s)", msgHead, "encoding", msgTail, response.c_str());
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   
*/
void TestCiphers::generateMatrix() {
  int mSize = cipher->getMatrixSize();
  int lSize = cipher->getLexigraphSize();
  assertm(mSize == lSize, "Matrix size mismatch");
  sprintf(buf, "%s [%s] %s", msgHead, "matrix generated", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
TestCiphers::~TestCiphers() { }
