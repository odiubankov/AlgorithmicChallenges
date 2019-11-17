#include "1219_PathWithMaximumGold.h"
#include <gtest/gtest.h>

TEST(MaxGold, test) {
    ASSERT_EQ(24, getMaximumGold({
                                     {0,6,0},
                                     {5,8,7},
                                     {0,9,0}
    }));
}

TEST(MaxGold, test2) {
    ASSERT_EQ(28, getMaximumGold({
        {1,0,7},
        {2,0,6},
        {3,4,5},
        {0,3,0},
        {9,0,20}
    }));
}

TEST(MaxGold, test3) {
    ASSERT_EQ(478, getMaximumGold({
        {0, 0, 0, 22,0, 24},
        {34,23,18,0, 23,2},
        {11,39,20,12,0, 0},
        {39,8, 0, 2, 0, 1},
        {19,32,26,20,20,30},
        {0, 38,26,0, 29,31}
    }));
}
