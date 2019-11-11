#include "1007_MinimumDominoRotations.h"
#include <gtest/gtest.h>

TEST(MinDominoRotations, test) {
    ASSERT_EQ(2, minDominoRotations({2,1,2,4,2,2}, {5,2,6,2,3,2}));
    ASSERT_EQ(-1, minDominoRotations({3,5,1,2,3}, {3,6,3,3,4}));
}
