#include "6_Conversion.h"
#include <gtest/gtest.h>

TEST(Conversion, test) {
    SolutionHammingDistance s;
    ASSERT_EQ(2, s.hammingDistance(29, 15));
    ASSERT_EQ(2, s.hammingDistance(1, 4));
}
