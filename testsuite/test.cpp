
#include "test.h"

TestSuite::TestSuite() {
    log = Logger::GetInstance();
    log->named_log(__FILE__, "Tester Loaded!");
}

TestSuite::~TestSuite() {}

int main(int argc, char const *argv[]) {
    TestSuite ts;
    return 0;
}
