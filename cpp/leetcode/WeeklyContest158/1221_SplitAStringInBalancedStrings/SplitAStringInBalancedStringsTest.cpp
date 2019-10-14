#include "SplitAStringInBalancedStrings.h"
#include <gtest/gtest.h>

TEST(SplitBalancedStr, test) {
    SolutionBS s;
    ASSERT_EQ(s.balancedStringSplit("RLRRLLRLRL"), 4);
    ASSERT_EQ(s.balancedStringSplit("RLLLLRRRLR"), 3);
    ASSERT_EQ(s.balancedStringSplit("LLLLRRRR"), 1);
}
