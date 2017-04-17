cmake_minimum_required(VERSION 3.6)
project(leetcodesolutions)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES LongestPalindromicSubstring.h LongestPalindromicSubstring.cpp)
add_executable(leetcodesolutions ${SOURCE_FILES})
target_link_libraries(leetcodesolutions gtest gtest_main)