cmake_minimum_required(VERSION 3.6)
project(leetcodesolutions)

set(CMAKE_CXX_STANDARD 14)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES LongestPalindromicSubstring.h LongestPalindromicSubstring.cpp LicenseKeyFormatting.h LicenseKeyFormatting.cpp PoorPigs.h PoorPigs.cpp LongestUniqCharsSubstr.h LongestUniqCharsSubstr.cpp)
add_executable(leetcodesolutions ${SOURCE_FILES})
target_link_libraries(leetcodesolutions gtest gtest_main)