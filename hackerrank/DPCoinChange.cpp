#include "DPCoinChange.h"
#include <gtest/gtest.h>

TEST(DPCoinChange, test)
{
    ASSERT_EQ(4, hackerrank::make_change(vector<int>{1,2,3}, 4));
    ASSERT_EQ(96190959, hackerrank::make_change(vector<int>{5,37,8,39,33,17,22,32,13,7,10,35,40,2,43,49,46,19,41,1,12,11,28}, 166));
}
