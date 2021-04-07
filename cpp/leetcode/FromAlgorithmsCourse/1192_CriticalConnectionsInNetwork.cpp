#include "1192_CriticalConnectionsInNetwork.h"
#include <gtest/gtest.h>

TEST(CriticalConnection, test) {
    vector<vector<int>> res{{1, 3}};
    ASSERT_EQ(res, criticalConnectionsTarjan(4, {{0,1},{1,2},{2,0},{1,3}}));
}

TEST(CriticalConnection, test2) {
    vector<vector<int>> res{{1, 3}};
    ASSERT_EQ(res, criticalConnectionsTarjan(6, {{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,3}}));
}

TEST(CriticalConnection, test3) {
    ASSERT_TRUE(criticalConnectionsTarjan(10, {{1,0},{2,0},{3,0},{4,1},{5,3},{6,1},{7,2},{8,1},{9,6},{9,3},{3,2},{4,2},{7,4},{6,2},{8,3},{4,0},{8,6},{6,5},{6,3},{7,5},{8,0},{8,5},{5,4},{2,1},{9,5},{9,7},{9,4},{4,3}}).empty());
}
