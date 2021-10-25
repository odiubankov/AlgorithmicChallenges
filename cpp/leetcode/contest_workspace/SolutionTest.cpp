#include "Solution.h"
#include <gtest/gtest.h>

TEST(BiweeklyContest11, test) {

//    string s1 = "daabcbaabcbc", s2 = "abc";
//    string s1 = "eemckxmckx", s2 = "emckx";
//    ASSERT_EQ("", removeOccurrences(s1, s2));
    vector<int> nums{5,6,7,8};
    ASSERT_EQ(maxAlternatingSum(nums), 8);
}
