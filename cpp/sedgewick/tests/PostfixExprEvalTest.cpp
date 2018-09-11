#include "../PostfixExprEval.h"
#include <gtest/gtest.h>


TEST(PostfixExprEval, test)
{
    EXPECT_EQ(sedgewick::postfixExprEval("123++8*"), 48);
    EXPECT_EQ(sedgewick::postfixExprEval("12+8*"), 24);
}