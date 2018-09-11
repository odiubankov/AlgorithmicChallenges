#include "../FibonacciNumber.h"
#include <gtest/gtest.h>

TEST(FimonacciNumber, test)
{
    EXPECT_EQ(0, sedgewick::calcFibonacciNumber(0));
    EXPECT_EQ(1, sedgewick::calcFibonacciNumber(1));
    EXPECT_EQ(1, sedgewick::calcFibonacciNumber(2));
    EXPECT_EQ(5, sedgewick::calcFibonacciNumber(5));
    EXPECT_EQ(1134903170, sedgewick::calcFibonacciNumber(45));
}
