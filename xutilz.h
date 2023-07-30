#ifndef XUTILZ_H
#define XUTILZ_H

#include <algorithm>
#include <string>
#include <ctime>

namespace Utilz {

    std::string FileName(const char *);
    std::string FileName(int, const char *);
    std::string TimeStamp();
    std::string HeadString(int, std::string);
    std::string TailString(int, std::string);
    void Strip(std::string&);

}; // namespace Utilz

#endif // XUTILZ_H //