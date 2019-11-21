#include "410_SplitArrayLargestSum.h"
#include <gtest/gtest.h>

TEST(SplitArrayLargestSum, test) {
    ASSERT_EQ(18, splitArray({7,2,5,10,8}, 2));
    ASSERT_EQ(18, splitArrayBST({7,2,5,10,8}, 2));
}

TEST(SplitArrayLargestSum, testIntOverflow) {
    ASSERT_EQ(2147483647, splitArray({1,2147483647}, 2));
}
