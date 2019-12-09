#include "Solution.h"
#include <gtest/gtest.h>

TEST(BiweeklyContest11, test) {
//    ASSERT_EQ("AEIDBCDIBC", toHexspeak("747823223228"));
//    vector<vector<int>> res{{0,1},{6,7}};
//    ASSERT_EQ(res, removeInterval({{0,2},{3,4},{5,7}}, {1,6}));
//    vector<vector<int>> res{{0,50}};
//    ASSERT_EQ(res, removeInterval({{0, 100}}, {50,100}));
//    vector<vector<int>> res2{{50,100}};
//    ASSERT_EQ(res2, removeInterval({{0, 100}}, {0,50}));

    ASSERT_EQ(2, deleteTreeNodes(7, {-1,0,0,1,2,2,2}, {1,-2,4,0,-2,-1,-1}));
}
