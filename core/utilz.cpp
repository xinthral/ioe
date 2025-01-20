#include "utilz.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Strips away the file extension 
*/
std::string Utilz::FileName(const char* file) {
  std::string fileName = file;
  size_t pos = fileName.find(".");
  return fileName.substr(0, pos);
}

/*!
 * @todo    Truncating method to strip away file extension 
*/
std::string Utilz::FileName(int length, const char* file) {
  std::string output = Utilz::FileName(file);
  return Utilz::HeadString(length, output);
}

/*!
 * @todo    Formatted Timestamp for uniformity
*/
std::string Utilz::TimeStamp() {
  PROFILE_FUNCTION();
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
 * @todo    Converts a string containing multiple words into
 *          into an array of strings.
*/
void Utilz::StringToArray(std::string input, std::vector<std::string>& output) {
  PROFILE_FUNCTION();
  char* token = strtok(const_cast<char*>(input.c_str()), " \r\n");
  while (token != NULL) {
    output.push_back(token);
    token = strtok(NULL, " \r\n");
  }
}

/*!
 * @todo    Truncates a string from the beginning of a string
*/
std::string Utilz::HeadString(int length, std::string input) {
  PROFILE_FUNCTION();
  std::string output = input;
  output.resize(length);
  return output;
}

/*!
 * @todo    Truncates a string from the ending of a string
*/
std::string Utilz::TailString(int length, std::string input) {
  PROFILE_FUNCTION();
  std::string output;
  size_t l = input.size() - length;
  for (size_t i = l; i < input.size(); i++) { output += input[i]; }
  return output;
}

/*!
 * @todo    Removes whitespace from string
*/
void Utilz::Strip(std::string& input) {
  PROFILE_FUNCTION();
  std::string::iterator pos = std::remove(input.begin(), input.end(), ' ');
  input.erase(pos, input.end());
}

/*!
 * @todo    Returns a randomly generated string
*/
std::string Utilz::randomString(int length) {
  PROFILE_FUNCTION();
  std::srand(std::time(nullptr));
  std::string lexigraph = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
  std::string output = "";
  int idx = -1;
  for (int i = 0; i < length; i++) {
    idx = rand() % lexigraph.size() + 1;
    output += lexigraph[idx];
  }
  return output;
}

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void Utilz::_help() {
  std::string helpline = "\nUtilz Helpline!\n";
  helpline += "\n";
  Logger::GetInstance()->named_log(__FILENAME__, helpline);
}

extern "C" {
  int addIt(int a, int b) {
    return a + b;
  }
}
