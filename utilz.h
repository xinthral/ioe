#ifndef UTILZ_H
#define UTILZ_H

#include <algorithm>
#include <ctime>
#include <iterator>
#include <string>

namespace Utilz {
    std::string FileName(const char *);
    std::string FileName(int, const char *);
    std::string TimeStamp();
    std::string HeadString(int, std::string);
    std::string TailString(int, std::string);
    void Strip(std::string&);
}; // namespace Utilz

#endif // UTILZ_H //