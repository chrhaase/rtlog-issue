//
// Created by Christian Haase on 30/05/2023.
//

#include "Logging.h"
#include "SomeClass.h"
#include <iostream>

int main()
{
    using namespace evr;
    EVR_RTLOG_DEBUG (LogRegion::Engine, "Hello World");

    SomeClass someClass {};

    auto printFunc = [] (LogData data, size_t n, const char* s, const char* m)
    { std::cout << to_string (data.region) << " " << n << " " << s << " " << m << std::endl; };
    gRealtimeLogger.PrintAndClearLogQueue (printFunc);
    return 0;
}