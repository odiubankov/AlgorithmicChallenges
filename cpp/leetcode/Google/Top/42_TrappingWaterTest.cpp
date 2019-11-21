#include "42_TrappingWatter.h"
#include <gtest/gtest.h>

TEST(TrappingWater, test) {
    ASSERT_EQ(6, trap({0,1,0,2,1,0,1,3,2,1,2,1}));
    ASSERT_EQ(1, trap({5,4,1,2}));
    ASSERT_EQ(6, trapSimple({0,1,0,2,1,0,1,3,2,1,2,1}));
    ASSERT_EQ(1, trapSimple({5,4,1,2}));
}
