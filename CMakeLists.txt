cmake_minimum_required(VERSION 3.6)
project(leetcodesolutions)

set(CMAKE_CXX_STANDARD 14)
set(BUILD_SHARED_LIBS OFF)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES FourSum.h FourSum.cpp LongestPalindromicSubstring.h LongestPalindromicSubstring.cpp LicenseKeyFormatting.h LicenseKeyFormatting.cpp PoorPigs.h PoorPigs.cpp LongestUniqCharsSubstr.h LongestUniqCharsSubstr.cpp BasicCalculator.h BasicCalculator.cpp RandomizedSet.h RandomizedSet.cpp GenerateParentheses.h GenerateParentheses.cpp hackerrank/ArraysLeftRotation.h hackerrank/ArraysLeftRotation.cpp hackerrank/StringsMakingAnagrams.h hackerrank/StringsMakingAnagrams.cpp hackerrank/HashTablesRansomNote.h hackerrank/LinkedListsDetectCycle.h hackerrank/StacksBalancedBrackets.h hackerrank/QueuesATaleOfTwoStacks.h hackerrank/TreesIsThisABinarySearchTree.h hackerrank/HeapsFindTheRunningMedian.h hackerrank/HeapsFindTheRunningMedian.cpp hackerrank/TriesContacts.h hackerrank/TriesContacts.cpp WordSearch.h WordSearch.cpp MaxPointsOnALine.h MaxPointsOnALine.cpp hackerrank/SortingBubbleSort.h hackerrank/SortingComparator.h hackerrank/MergeSortCountingInversions.h hackerrank/MergeSortCountingInversions.cpp hackerrank/DPCoinChange.h hackerrank/DPCoinChange.cpp hackerrank/BinarySearchIceCreamParlor.h hackerrank/BinarySearchIceCreamParlor.cpp hackerrank/ConnectedCellInGrid.cpp hackerrank/ConnectedCellInGrid.h)
add_executable(leetcodesolutions ${SOURCE_FILES})
target_link_libraries(leetcodesolutions gtest gtest_main)