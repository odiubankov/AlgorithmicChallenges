#include "../PoorPigs.h"
#include <gtest/gtest.h>

namespace leetcode
{

TEST(PoorPigs, test)
{
    Solution solution;
    ASSERT_EQ(5, solution.poorPigs(1000, 15, 60));
    ASSERT_EQ(4, solution.poorPigs(1000, 12, 60));
}

}//namespace leetcode

