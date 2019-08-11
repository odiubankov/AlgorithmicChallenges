#include "../BagsQueuesStacks_1.3.37_JosephusProblem.h"
#include <gtest/gtest.h>

TEST(BagsQueuesStacks_JosephusProblem, test)
{
    std::vector<int> result{1, 3, 5, 0, 4, 2, 6};
    ASSERT_EQ(sedgewick::josephusProblem(2, 7), result);
}
