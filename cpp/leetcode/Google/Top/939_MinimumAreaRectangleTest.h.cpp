#include "939_MinimumAreaRectangle.h"
#include <gtest/gtest.h>

TEST(MinimumAreaRectangle, test) {
    ASSERT_EQ(minAreaRect({{1,1},{1,3},{3,1},{3,3},{2,2}}), 4);
}