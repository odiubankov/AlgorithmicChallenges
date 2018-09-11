#include "../InfixToPostfix.h"
#include <gtest/gtest.h>


TEST(InfixToPostfix, test)
{
    EXPECT_EQ(sedgewick::shuntingYard("(1 + 2 + 3) * 8"), "123++8*");
    EXPECT_EQ(sedgewick::shuntingYard("(1 + 2) * 8"), "12+8*");
}
