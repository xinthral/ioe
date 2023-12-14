/*!
 * @class   Utilz utilz.h utilz.cpp
 * @brief   Utility functions I find useful enough to not want 
 *          to have to repeat myself.
*/
#include "utilz.h"

/*!
 * @brief   Strips away the file extension 
 * @param[in] __FILE__ - the file extension
 * @return   A new string with the tld stripped.
*/
std::string Utilz::FileName(const char* file) {
  std::string fileName = file;
  size_t pos = fileName.find(".");
  return fileName.substr(0, pos);
}

/*!
 * @brief   Truncating method to strip away file extension 
 * @param[in] length   - Size of return string
 * @param[in] __FILE__ - the file extension
 * @return   A new string containing a truncated Filename 
*/
std::string Utilz::FileName(int length, const char* file) {
  std::string output = Utilz::FileName(file);
  return Utilz::HeadString(length, output);
}

/*!
 * @brief   Formatted Timestamp for uniformity
 * @return  A string containing the time in a pre-formatted
 *          way.
*/
std::string Utilz::TimeStamp() {
  std::time_t time = std::time({});
  char output[std::size("ddd mmm dd hh:mm:ss")];
  std::string fmtString = "%a %b %d %T";
  std::strftime(
    std::data(output), 
    std::size(output), 
    fmtString.c_str(), 
    std::localtime(&time)
  );
  return output;
}

/*!
 * @brief   Converts a string containing multiple words into
 *          into an array of strings.
 * @param[in]   input - String to be parsed
 * @param[out] output - Vector of strings to put parsed words  
*/
void Utilz::StringToArray(std::string input, std::vector<std::string>& output) {
  char* token = strtok(const_cast<char*>(input.c_str()), " ");
  while (token != NULL) {
    output.push_back(token);
    token = strtok(NULL, " \n");
  }
}

/*!
 * @brief   Truncates a string from the beginning of a string
 * @param[in] length  - Size of return string
 * @param[in] message - String to be truncated
 * @return  A new string truncated from the front 
*/
std::string Utilz::HeadString(int length, std::string input) {
  std::string output = input;
  output.resize(length);
  return output;
}

/*!
 * @brief   Truncates a string from the ending of a string
 * @param[in] length  - Size of return string
 * @param[in] message - String to be truncated
 * @return  A new string truncated from the back
*/
std::string Utilz::TailString(int length, std::string input) {
  std::string output;
  size_t l = input.size() - length;
  for (size_t i = l; i < input.size(); i++) { output += input[i]; }
  return output;
}

/*!
 * @brief   Removes whitespace from string
 * @param[in] message - String to be crunched
*/
void Utilz::Strip(std::string& input) {
  std::string::iterator pos = std::remove(input.begin(), input.end(), ' ');
  input.erase(pos, input.end());
}

extern "C" {
  int addIt(int a, int b) {
    return a + b;
  }
}