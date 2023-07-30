#ifndef XUTILZ_H
#define XUTILZ_H

#include <algorithm>
#include <string>
#include <ctime>

namespace Utilz {

    std::string FileName(const char *);
    std::string TimeStamp();
    void Strip(std::string&);

}; // namespace Utilz

#endif // XUTILZ_H //