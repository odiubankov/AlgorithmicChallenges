#include "../BagsQueuesStacks_1.3.9_FixInfixExpression.h"
#include <gtest/gtest.h>

TEST(BagsQueuesStacks_FixInfixExpression, test_one_num_digit)
{
    ASSERT_EQ(sedgewick::fixInfix("1+2)*3-4)*5-6)))"), "((1+2)*((3-4)*(5-6)))");
}


TEST(BagsQueuesStacks_FixInfixExpression, test_multiple_nums_digits)
{
    ASSERT_EQ(sedgewick::fixInfix("10+21)*32-43)*54-65)))"), "((10+21)*((32-43)*(54-65)))");
}
