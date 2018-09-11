#include "../FixInfixExpression.h"
#include <gtest/gtest.h>


TEST(FixInfixExpression, test)
{
    EXPECT_EQ("( ( 1 + 2 ) * ( ( 3 - 4 ) * ( 5 - 6 ) ) )",
              sedgewick::fixInfixExpression("1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )"));
}
