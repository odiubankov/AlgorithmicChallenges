#include "../BasicCalculator.h"
#include <gtest/gtest.h>

namespace leetcode {

TEST(BasicCalculator, test) {
    EXPECT_EQ(calculate("3+2*2"), 7);
    EXPECT_EQ(calculate(" 3/2 "), 1);
    EXPECT_EQ(calculate(" 3+5 / 2 "), 5);
    EXPECT_EQ(calculate("0"), 0);
    EXPECT_EQ(calculate("1+1-1"), 1);
    EXPECT_EQ(calculate("2+3+4"), 9);
}

}//namespace leetcode