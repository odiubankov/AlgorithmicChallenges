#include "../BagsQueuesStacks_1.3.10_InfixToPostfix.h"
#include <gtest/gtest.h>

TEST(BagsQueuesStacks_InfixToPostfix, test_one_digit)
{
    ASSERT_EQ(sedgewick::infixToPostfix("((1+2)*((3-4)*(5-6)))"), "1 2+3 4-5 6-**");
}

TEST(BagsQueuesStacks_InfixToPostfix, test_multiple_digits)
{
ASSERT_EQ(sedgewick::infixToPostfix("((10+21)*((32-43)*(54-65)))"), "10 21+32 43-54 65-**");
}
