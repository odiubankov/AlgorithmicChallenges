#include "850_RectangleAreaII.h"
#include <gtest/gtest.h>

TEST(RectangleArea, test) {
    ASSERT_EQ(6, rectangleArea({{0,0,2,2}, {1,0,2,3}, {1,0,3,1}}));
}

TEST(RectangleArea, test2) {
    ASSERT_EQ(49, rectangleArea({{0,0,1000000000,1000000000}}));
}