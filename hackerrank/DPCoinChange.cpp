#include "DPCoinChange.h"
#include <gtest/gtest.h>

TEST(DPCoinChange, test)
{
    ASSERT_EQ(4, hackerrank::make_change(vector<int>{1,2,3}, 4));
}
