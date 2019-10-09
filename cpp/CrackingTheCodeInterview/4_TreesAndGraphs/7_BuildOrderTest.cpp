#include "7_BuildOrder.h"
#include <gtest/gtest.h>

TEST(TopologicalSort, test) {
    SolutionTopologicalSort s;
    std::vector<int> expectedRes{0, 1};
    ASSERT_EQ(expectedRes, s.findOrder(2, {{1, 0}}));
}

TEST(TopologicalSort, test2) {
    SolutionTopologicalSort s;
    std::vector<int> expectedRes1{0,1,2,3}, expectedRes2{0,2,1,3};
    auto res = s.findOrder(4, {{1,0},{2,0},{3,1},{3,2}});
    ASSERT_TRUE(expectedRes1 == res || expectedRes2 == res);
}

TEST(TopologicalSort, invalidOrder) {
    SolutionTopologicalSort s;
    ASSERT_TRUE(s.findOrder(2, {{1,0},{0,1}}).empty());
}
