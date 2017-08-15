cmake_minimum_required(VERSION 3.6)
project(algorithmicchallenges)

set(CMAKE_CXX_STANDARD 14)
set(BUILD_SHARED_LIBS OFF)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif ()

add_subdirectory(libs/googletest)
include_directories(libs/googletest/googletest/include)

set(SOURCE_FILES
        FourSum.h /
        FourSum.cpp /
        LongestPalindromicSubstring.h /
        LongestPalindromicSubstring.cpp /
        LicenseKeyFormatting.h /
        LicenseKeyFormatting.cpp /
        PoorPigs.h PoorPigs.cpp /
        LongestUniqCharsSubstr.h /
        LongestUniqCharsSubstr.cpp /
        BasicCalculator.h /
        BasicCalculator.cpp /
        RandomizedSet.h /
        RandomizedSet.cpp /
        GenerateParentheses.h /
        GenerateParentheses.cpp /
        WordSearch.h /
        WordSearch.cpp /
        MaxPointsOnALine.h /
        MaxPointsOnALine.cpp /
        SubStringSearchKMP.h /
        SubStringSearchKMP.cpp /
        AsyncLogger.h /
        AsyncLogger.cpp /
        StringOneAway.h /
        StringOneAway.cpp/

        hackerrank/ArraysLeftRotation.h /
        hackerrank/StringsMakingAnagrams.h /
        hackerrank/HashTablesRansomNote.h /
        hackerrank/LinkedListsDetectCycle.h /
        hackerrank/StacksBalancedBrackets.h /
        hackerrank/QueuesATaleOfTwoStacks.h /
        hackerrank/TreesIsThisABinarySearchTree.h /
        hackerrank/HeapsFindTheRunningMedian.h /
        hackerrank/TriesContacts.h /
        hackerrank/SortingBubbleSort.h /
        hackerrank/SortingComparator.h /
        hackerrank/MergeSortCountingInversions.h /
        hackerrank/ConnectedCellInGrid.h /
        hackerrank/BFSShortestReachInAGraph.h /
        hackerrank/IsPrimeNumber.h /
        hackerrank/DPCoinChange.h /
        hackerrank/BinarySearchIceCreamParlor.h /

        hackerrank/tests/BinarySearchIceCreamParlor.cpp /
        hackerrank/tests/ConnectedCellInGrid.cpp /
        hackerrank/tests/DPCoinChange.cpp /
        hackerrank/tests/ArraysLeftRotation.cpp /
        hackerrank/tests/StringsMakingAnagrams.cpp /
        hackerrank/tests/HeapsFindTheRunningMedian.cpp /
        hackerrank/tests/TriesContacts.cpp /
        hackerrank/tests/MergeSortCountingInversions.cpp /

        ostd/Vector.cpp /
        ostd/Vector.h /
        ostd/UniquePtr.h /
        ostd/UniquePtr.cpp /
        ostd/SharedPtr.h /
        ostd/SharedPtr.cpp /
        ostd/IsBaseOf.h /
        ostd/IsBaseOf.cpp /
        ostd/IsSame.h /
        ostd/IsSame.cpp /
        ostd/Distance.h /
        ostd/Distance.cpp)

add_executable(algorithmicchallenges ${SOURCE_FILES})
target_link_libraries(algorithmicchallenges gtest gtest_main)