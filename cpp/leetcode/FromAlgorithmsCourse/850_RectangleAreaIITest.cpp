#include "850_RectangleAreaII.h"
#include <gtest/gtest.h>

TEST(RectangleArea, test) {
    ASSERT_EQ(6, rectangleArea({{0,0,2,2}, {1,0,2,3}, {1,0,3,1}}));
}
