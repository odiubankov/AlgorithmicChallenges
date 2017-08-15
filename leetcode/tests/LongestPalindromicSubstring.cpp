#include "../LongestPalindromicSubstring.h"
#include <gtest/gtest.h>

namespace leetcode
{

TEST(LongestPalindrome, test)
{
    Solution solution;
    ASSERT_EQ("aabaa", solution.longestPalindrome("aabaa"));
    ASSERT_EQ("bbb", solution.longestPalindrome("aabbb"));
    ASSERT_EQ("bb", solution.longestPalindrome("cbbd"));
    ASSERT_EQ("anana", solution.longestPalindrome("bananas"));
    ASSERT_EQ("aaabaaa", solution.longestPalindrome("aaabaaaa"));
}

}//namespace leetcode


