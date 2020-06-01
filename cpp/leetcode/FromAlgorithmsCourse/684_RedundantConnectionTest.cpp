#include "684_RedundantConnection.h"
#include <gtest/gtest.h>

TEST(RedundantConnection, test) {
    vector<int> expectedResult{1, 4};
    ASSERT_EQ(expectedResult, findRedundantConnectionUnionFind({{1,2},{2,3},{3,4},{1,4},{1,5}}));
}
