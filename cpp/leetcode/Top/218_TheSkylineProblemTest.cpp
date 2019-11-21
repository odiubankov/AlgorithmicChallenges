#include "218_TheSkylineProblem.h"
#include <gtest/gtest.h>

TEST(Skyline, test) {
    vector<vector<int>> res{{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}};
    ASSERT_EQ(res, getSkyline({{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}}));
}
