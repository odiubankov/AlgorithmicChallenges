#include "QueensThatCanAttackTheKing.h"
#include <gtest/gtest.h>

TEST(QueensAttackTheKing, test) {
    SolutionQueensAttackTheKing s;
    ASSERT_EQ(s.queensAttacktheKing({{0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}}, {3,3}).size(), 3);
    ASSERT_EQ(s.queensAttacktheKing({{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}}, {0,0}).size(), 3);
}
