#include "135_Candy.h"
#include <gtest/gtest.h>

TEST(Candy, test1) {
    ASSERT_EQ(5, candy({1, 0, 2}));
    ASSERT_EQ(4, candy({1,2,2}));
}

TEST(Candy, test2) {
    ASSERT_EQ(5, candyTwoArrays({1, 0, 2}));
    ASSERT_EQ(4, candyTwoArrays({1,2,2}));
}

TEST(Candy, test3) {
    ASSERT_EQ(18, candyTwoArrays({1,6,10,8,7,3,2}));
}
