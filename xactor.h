#ifndef XACTOR_H
#define XACTOR_H

#include <string>

class Actor {
private:
    int id;
    std::string name;
public:
    Actor();
    int get_id();
    void set_id(int);
    std::string get_name();
    void set_name(std::string);
    ~Actor();
};

#endif // XACTOR_H //