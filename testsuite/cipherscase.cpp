#include "cipherscase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
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
 * @todo    Run full set of test on module 
*/
void TestCiphers::test_all() {
  this->generateMatrix();
  this->encode();
  this->decode();
  // this->swappedLexigraph(); 
}

/*!
 * @todo    FIXME
*/
void TestCiphers::displayMatrix() {
  PROFILE_FUNCTION();
  cipher->displayMatrix(false);
  sprintf(buf, "%s [%s] %s", msgHead, "matrix display", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Ensuring that the cipher can properly decode a message
*/
void TestCiphers::decode() {
  PROFILE_FUNCTION();
  std::string response = cipher->decode(encoded);
  sprintf(buf, "Decoding failed to produce %s: %s => %s", this->decoded.c_str(), this->encoded.c_str(), response.c_str());
  assertm(strcmp(response.c_str(), this->decoded.c_str()) == 0, buf);
  sprintf(buf, "%s [%s] %s (%s)", msgHead, "decoding", msgTail, response.c_str());
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Ensuring that the cipher can properly encode a message
*/
void TestCiphers::encode() {
  PROFILE_FUNCTION();
  this->encoded = cipher->encode(decoded);
  sprintf(buf, "Encoding failed to produce %s: %s => %s", this->encoded.c_str(), this->decoded.c_str(), this->encoded.c_str());
  assertm(this->encoded.size() > 0, buf);
  sprintf(buf, "%s [%s] %s (%s)", msgHead, "encoding", msgTail, this->encoded.c_str());
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Generates Cipher Matrices'
*/
void TestCiphers::generateMatrix() {
  PROFILE_FUNCTION();
  int mSize = cipher->getMatrixSize();
  int lSize = cipher->getLexigraphSize();
  assertm(mSize == lSize, "Matrix size mismatch");
  sprintf(buf, "%s [%s] %s", msgHead, "matrix generated", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Generates Cipher after changing the lexigraph
*/
void TestCiphers::swappedLexigraph() {
  PROFILE_FUNCTION();
  cipher->setLexigraph("1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  this->encode();
  this->decode();
  sprintf(buf, "Dec: %s", this->decoded.c_str());
  BaseCase::log->named_log(__FILENAME__, buf);
  sprintf(buf, "%s [%s] %s (%d)", msgHead, "new lexigraph", msgTail, cipher->getLexigraphSize());
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestCiphers::~TestCiphers() { }
