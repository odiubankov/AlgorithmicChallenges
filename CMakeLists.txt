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
        leetcode/PoorPigs.h /
        leetcode/LongestUniqCharsSubstr.h /
        leetcode/BasicCalculator.h /
        leetcode/RandomizedSet.h /
        leetcode/GenerateParentheses.h /
        leetcode/WordSearch.h /
        leetcode/MaxPointsOnALine.h /
        leetcode/SubStringSearchKMP.h /
        leetcode/StringOneAway.h /

        leetcode/tests/LongestPalindromicSubstringTest.cpp /
        leetcode/tests/LicenseKeyFormattingTest.cpp /
        leetcode/tests/PoorPigsTest.cpp /
        leetcode/tests/LongestUniqCharsSubstrTest.cpp /
        leetcode/tests/BasicCalculatorTest.cpp /
        leetcode/tests/RandomizedSetTest.cpp /
        leetcode/tests/GenerateParenthesesTest.cpp /
        leetcode/tests/WordSearchTest.cpp /
        leetcode/tests/MaxPointsOnALineTest.cpp /
        leetcode/tests/SubStringSearchKMPTest.cpp /
        leetcode/tests/StringOneAwayTest.cpp /

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
        hackerrank/RoadsAndLibs.h /
        hackerrank/BigSorting.h /
        hackerrank/Equal.h /

        hackerrank/tests/BinarySearchIceCreamParlorTest.cpp /
        hackerrank/tests/ConnectedCellInGridTest.cpp /
        hackerrank/tests/DPCoinChangeTest.cpp /
        hackerrank/tests/ArraysLeftRotationTest.cpp /
        hackerrank/tests/StringsMakingAnagramsTest.cpp /
        hackerrank/tests/HeapsFindTheRunningMedianTest.cpp /
        hackerrank/tests/TriesContactsTest.cpp /
        hackerrank/tests/MergeSortCountingInversionsTest.cpp /
        hackerrank/tests/RoadsAndLibsTest.cpp /
        hackerrank/tests/EqualTest.cpp /

        sedgewick/FibonacciNumber.h /
        sedgewick/FixInfixExpression.h /
        sedgewick/GreatestCommonDivisor.h /
        sedgewick/InfixToPostfix.h /
        sedgewick/PostfixExprEval.h /

        sedgewick/FibonacciNumber.cpp /
        sedgewick/FixInfixExpression.cpp /
        sedgewick/GreatestCommonDivisor.cpp /
        sedgewick/InfixToPostfix.cpp /
        sedgewick/PostfixExprEval.cpp / 

        sedgewick/tests/FibonacciNumberTest.cpp /
        sedgewick/tests/FixInfixExpressionTest.cpp /
        sedgewick/tests/GreatestCommonDivisorTest.cpp /
        sedgewick/tests/InfixToPostfixTest.cpp / 
        sedgewick/tests/PostfixExprEvalTest.cpp)

add_executable(algorithmicchallenges ${SOURCE_FILES})
target_link_libraries(algorithmicchallenges gtest gtest_main)