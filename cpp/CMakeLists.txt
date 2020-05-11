cmake_minimum_required(VERSION 3.6)
project(algorithmicchallenges)

set(CMAKE_CXX_STANDARD 17)
set(BUILD_SHARED_LIBS OFF)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
#    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif ()

add_subdirectory(libs/googletest)
include_directories(libs/googletest/googletest/include)

file(GLOB_RECURSE SOURCE_FILES
        hackerrank/*.cpp /
        hackerrank/*.h /
        leetcode/*.cpp /
        leetcode/*.h /
        CrackingTheCodeInterview/*.cpp /
        CrackingTheCodeInterview/*.h /
        sedgewick/*.cpp /
        sedgewick/*.h)

add_executable(algorithmicchallenges ${SOURCE_FILES})
target_link_libraries(algorithmicchallenges gtest gtest_main)