#include "1_TwoSum.h"
#include <gtest/gtest.h>

TEST(TwoSum, test) {
    std::vector<int> res{0, 1};
//    ASSERT_EQ(res, twoSum({2, 7, 11, 15}, 9));
    ASSERT_EQ(res, twoSum({3, 3}, 6));
}
