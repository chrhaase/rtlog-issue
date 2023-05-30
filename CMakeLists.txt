cmake_minimum_required(VERSION 3.0)
project(rtlog-issue VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(rtlog-cpp
        GIT_REPOSITORY https://github.com/cjappl/rtlog-cpp
        GIT_PROGRESS TRUE
        GIT_REMOTE_UPDATE_STRATEGY CHECKOUT
        GIT_TAG b834c53
        )

FetchContent_MakeAvailable(rtlog-cpp)

add_executable(audioapp Logging.cpp main.cpp)
target_link_libraries(audioapp
        PRIVATE
        rtlog::rtlog
        )