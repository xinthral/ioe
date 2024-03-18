#ifndef UTILZ_H
#define UTILZ_H

#include <algorithm>
#include <ctime>
#include <iterator>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <vector>
#include "logger.h"

/*!
 * @class   Utilz utilz.h utilz.cpp
 * @brief   Utility functions I find useful.
*/
namespace Utilz {
  /*!
   * @brief   Strips away the file extension 
   * @param[in] __FILE__ - the file extension
   * @return   A new string with the tld stripped.
  */
  std::string FileName(const char *);

  /*!
   * @brief   Truncating method to strip away file extension 
   * @param[in] length   - Size of return string
   * @param[in] __FILE__ - the file extension
   * @return   A new string containing a truncated Filename 
  */
  std::string FileName(int, const char *);

  /*!
   * @brief   Formatted Timestamp for uniformity
   * @return  A string containing the time in a pre-formatted
   *          way.
  */
  std::string TimeStamp();

  /*!
   * @brief   Converts a string containing multiple words into
   *          into an array of strings.
   * @param[in]   input - String to be parsed
   * @param[out] output - Vector of strings to put parsed words  
  */
  void StringToArray(std::string, std::vector<std::string>&);

  /*!
   * @brief   Truncates a string from the beginning of a string
   * @param[in] length  - Size of return string
   * @param[in] message - String to be truncated
   * @return  A new string truncated from the front 
  */
  std::string HeadString(int, std::string);

  /*!
   * @brief   Truncates a string from the ending of a string
   * @param[in] length  - Size of return string
   * @param[in] message - String to be truncated
   * @return  A new string truncated from the back
  */
  std::string TailString(int, std::string);

  /*!
   * @brief   Removes whitespace from string
   * @param[in] message - String to be crunched
  */
  void Strip(std::string&);

  /*!
   * @brief   Returns a randomly generated string
  */
  std::string randomString(int);

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();
} // namespace Utilz

extern "C" {
  int addIt(int, int);
}

#endif // UTILZ_H //
