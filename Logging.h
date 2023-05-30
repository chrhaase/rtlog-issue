//
// Created by Christian Haase on 30/05/2023.
//

#pragma once
#include <rtlog/rtlog.h>

#ifndef DECLARE_GLOBAL_VARIABLES_EXTERN
#define DECLARE_GLOBAL_VARIABLES_EXTERN 1
#endif

namespace evr
{

constexpr auto MAX_LOG_MESSAGE_LENGTH = 256;
constexpr auto MAX_NUM_LOG_MESSAGES = 100;

enum class LogLevel
{
    Debug,
    Info,
    Warning,
    Critical
};
enum class LogRegion
{
    Engine,
    Game,
    Network,
    Audio
};

const char* to_string (LogLevel level);
const char* to_string (LogRegion region);

struct LogData
{
    LogLevel level;
    LogRegion region;
};

#if DECLARE_GLOBAL_VARIABLES_EXTERN
extern std::atomic<std::size_t> gSequenceNumber;
using RealtimeLogger =
    rtlog::Logger<LogData, MAX_NUM_LOG_MESSAGES, MAX_LOG_MESSAGE_LENGTH, gSequenceNumber>;

extern RealtimeLogger gRealtimeLogger;
#else
static std::atomic<std::size_t> gSequenceNumber;
using RealtimeLogger =
    rtlog::Logger<LogData, MAX_NUM_LOG_MESSAGES, MAX_LOG_MESSAGE_LENGTH, gSequenceNumber>;

static RealtimeLogger gRealtimeLogger;
#endif

#define EVR_RTLOG_DEBUG(Region, fstring, ...)                                                      \
    gRealtimeLogger.Log ({ LogLevel::Debug, Region }, fstring, ##__VA_ARGS__)
#define EVR_RTLOG_INFO(Region, fstring, ...)                                                       \
    gRealtimeLogger.Log ({ LogLevel::Info, Region }, fstring, ##__VA_ARGS__)
#define EVR_RTLOG_WARNING(Region, fstring, ...)                                                    \
    gRealtimeLogger.Log ({ LogLevel::Warning, Region }, fstring, ##__VA_ARGS__)
#define EVR_RTLOG_CRITICAL(Region, fstring, ...)                                                   \
    gRealtimeLogger.Log ({ LogLevel::Critical, Region }, fstring, ##__VA_ARGS__)

} // namespace evr
