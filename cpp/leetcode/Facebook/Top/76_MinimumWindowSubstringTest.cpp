#include "76_MinimumWindowSubstring.h"
#include <gtest/gtest.h>

TEST(MinWindowsSubstr, test) {
    ASSERT_EQ("BANC", minWindow("ADOBECODEBANC", "ABC"));
}

TEST(MinWindowsSubstr, test2) {
    ASSERT_EQ("ba", minWindow("bba", "ab"));
}

TEST(MinWindowsSubstr, test3) {
    ASSERT_EQ("a", minWindow("a", "a"));
}

TEST(MinWindowsSubstr, test4) {
    ASSERT_EQ("aaa", minWindow("aaflslflsldkalskaaa", "aaa"));
}

TEST(MinWindowsSubstr, test5) {
    ASSERT_EQ("ebac", minWindow("abcabdebac", "cea"));
}
