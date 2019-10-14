#include "DiceRollSimulation.h"
#include <gtest/gtest.h>

TEST(DiceRollSimulation, test) {
    SolutionDiceRollSimulation s;
    ASSERT_EQ(30, s.dieSimulator(2, {1,1,1,1,1,1}));
    ASSERT_EQ(34, s.dieSimulator(2, {1,1,2,2,2,3}));
    ASSERT_EQ(181, s.dieSimulator(3, {1,1,1,2,2,3}));
}
