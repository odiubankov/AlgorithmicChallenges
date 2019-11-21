#include "363.MaxSumOfRectangleNoLargerThanK.h"
#include <gtest/gtest.h>

TEST(MaxSum, test) {
    ASSERT_EQ(10, maxSumSubmatrix({{5,-4,-3,4},{-3,-4,4,5},{5,1,5,-4}}, 10));
}

TEST(MaxSum, test2) {
    ASSERT_EQ(2, maxSumSubmatrix({{2, 2, -1}}, 2));
}

TEST(MaxSum, test3) {
    ASSERT_EQ(-1, maxSumSubmatrix({{2, 2, -1}}, 0));
}
