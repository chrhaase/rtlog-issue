//
// Created by Christian Haase on 30/05/2023.
//

#include "Logging.h"

int main()
{
    using namespace evr;
    EVR_RTLOG_DEBUG (LogRegion::Engine, "Hello World");
    return 0;
}