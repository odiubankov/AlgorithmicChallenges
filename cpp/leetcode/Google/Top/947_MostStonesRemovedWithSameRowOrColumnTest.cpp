#include "947_MostStonesRemovedWithSameRowOrColumn.h"
#include <gtest/gtest.h>

TEST(MoveStones, test) {
    ASSERT_EQ(5, removeStones({{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}}));
    ASSERT_EQ(3, removeStones({{0,0},{0,2},{1,1},{2,0},{2,2}}));
    ASSERT_EQ(0, removeStones({{0,0}}));

    ASSERT_EQ(5, removeStonesUnionFind({{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}}));
    ASSERT_EQ(3, removeStonesUnionFind({{0,0},{0,2},{1,1},{2,0},{2,2}}));
    ASSERT_EQ(0, removeStonesUnionFind({{0,0}}));
}

TEST(MoveStones, test2) {
    ASSERT_EQ(19, removeStones({{5,9},{9,0},{0,0},{7,0},{4,3},{8,5},{5,8},{1,1},{0,6},{7,5},{1,6},{1,9},{9,4},{2,8},{1,3},{4,2},{2,5},{4,1},{0,2},{6,5}}));
}

TEST(MoveStones, test3) {
    ASSERT_EQ(10, removeStonesUnionFind({{0,0},{0,1},{1,0},{1,1},{2,1},{2,2},{3,2},{3,3},{3,4},{4,3},{4,4}}));
}

TEST(MoveStones, test4) {
    ASSERT_EQ(4, removeStonesUnionFind({{3,2},{3,1},{4,4},{1,1},{0,2},{4,0}}));
}
