#include "../GreatestCommonDivisor.h"
#include <gtest/gtest.h>


TEST(GreatestCommonDivisor, test)
{
    EXPECT_EQ(sedgewick::greatestCommonDivisor(105, 24), 3);
    EXPECT_EQ(sedgewick::greatestCommonDivisor(1111111, 1234567), 1);
}
