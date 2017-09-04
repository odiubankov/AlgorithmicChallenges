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
        leetcode/FourSum.h /
        leetcode/LongestPalindromicSubstring.h /
        leetcode/LicenseKeyFormatting.h /
        leetcode/PoorPigs.h
        leetcode/LongestUniqCharsSubstr .h /
        leetcode/BasicCalculator.h /
        leetcode/RandomizedSet.h /
        leetcode/GenerateParentheses.h /
        leetcode/WordSearch.h /
        leetcode/MaxPointsOnALine.h /
        leetcode/SubStringSearchKMP.h /
        leetcode/StringOneAway.h /

        leetcode/tests/LongestPalindromicSubstring.cpp /
        leetcode/tests/LicenseKeyFormatting.cpp /
        leetcode/tests/PoorPigs.cpp /
        leetcode/tests/LongestUniqCharsSubstr.cpp /
        leetcode/tests/BasicCalculator.cpp /
        leetcode/tests/RandomizedSet.cpp /
        leetcode/tests/GenerateParentheses.cpp /
        leetcode/tests/WordSearch.cpp /
        leetcode/tests/MaxPointsOnALine.cpp /
        leetcode/tests/SubStringSearchKMP.cpp /
        leetcode/tests/StringOneAway.cpp/

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
        hackerrank/tests/MergeSortCountingInversions.cpp)

add_executable(algorithmicchallenges ${SOURCE_FILES})
target_link_libraries(algorithmicchallenges gtest gtest_main)