#include "PlayWithChips.h"
#include <gtest/gtest.h>

TEST(MooveChips, test) {
    SolutionPlayWithChips s;
    ASSERT_EQ(1, s.minCostToMoveChips({1,2,3}));
    ASSERT_EQ(2, s.minCostToMoveChips({2,2,2,3,3}));
}
