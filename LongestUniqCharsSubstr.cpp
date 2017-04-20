#include "LongestUniqCharsSubstr.h"
#include <gtest/gtest.h>

TEST(LongestUniqCharsSubstr, test)
{
  longestuniqcharssubstr::Solution solution;
  ASSERT_EQ(3, solution.lengthOfLongestSubstring("abcabcbb"));
  ASSERT_EQ(1, solution.lengthOfLongestSubstring("bbbbb"));
  ASSERT_EQ(3, solution.lengthOfLongestSubstring("pwwkew"));
  ASSERT_EQ(1, solution.lengthOfLongestSubstring("c"));
  ASSERT_EQ(7, solution.lengthOfLongestSubstring("bpfbhmipx"));
}
