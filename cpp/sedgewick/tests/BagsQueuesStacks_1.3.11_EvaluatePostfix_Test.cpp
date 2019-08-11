#include "../BagsQueuesStacks_1.3.11_EvaluatePostfix.h"
#include <gtest/gtest.h>

TEST(BagsQueuesStacks_EvaluatePostfix, test)
{
    ASSERT_EQ(sedgewick::evaluatePostfix("10 21+32 43-54 65-**"), 3751);
}
