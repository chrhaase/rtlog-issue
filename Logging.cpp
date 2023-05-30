//
// Created by Christian Haase on 30/05/2023.
//

#include "Logging.h"
namespace evr
{

const char* to_string (LogLevel level)
{
    switch (level)
    {
        case LogLevel::Debug: return "DEBG";
        case LogLevel::Info: return "INFO";
        case LogLevel::Warning: return "WARN";
        case LogLevel::Critical: return "CRIT";
        default: return "Unknown";
    }
}

const char* to_string (LogRegion region)
{
    switch (region)
    {
        case LogRegion::Engine: return "ENGIN";
        case LogRegion::Game: return "GAME ";
        case LogRegion::Network: return "NETWK";
        case LogRegion::Audio: return "AUDIO";
        default: return "UNKWN";
    }
}

} // namespace evr