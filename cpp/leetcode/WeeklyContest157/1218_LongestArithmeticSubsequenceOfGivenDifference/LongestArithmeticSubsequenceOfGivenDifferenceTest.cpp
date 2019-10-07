#include "LongestArithmeticSubsequenceOfGivenDifference.h"
#include <gtest/gtest.h>

TEST(LongestSubsequence, test) {
    SolutionLongestSubsequence s;
    std::vector<int> vals1{1,2,3,4};
    ASSERT_EQ(4, s.longestSubsequence(vals1, 1));

    std::vector<int> vals2{1,3,5,7};
    ASSERT_EQ(1, s.longestSubsequence(vals2, 1));

    std::vector<int> vals3{1,5,7,8,5,3,4,2,1};
    ASSERT_EQ(4, s.longestSubsequence(vals3, -2));
}
