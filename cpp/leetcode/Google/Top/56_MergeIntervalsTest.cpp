#include "56_MergeIntervals.h"
#include <gtest/gtest.h>

TEST(MergeIntervals, test) {
    std::vector<std::vector<int>> res1{{1,6},{8,10},{15,18}};
    ASSERT_EQ(res1, merge({{1,3},{2,6},{8,10},{15,18}}));
    std::vector<std::vector<int>> res2{{1,5}};
    ASSERT_EQ(res2, merge({{1,4},{4,5}}));
    std::vector<std::vector<int>> res3{{1,4}};
    ASSERT_EQ(res3, merge({{1,4},{1, 4}}));
    std::vector<std::vector<int>> res4{{1,4}};
    ASSERT_EQ(res4, merge({{1,4},{2, 3}}));

    std::vector<std::vector<int>> src1{{1,3},{2,6},{8,10},{15,18}};
    ASSERT_EQ(res1, mergeSimple(src1));
    std::vector<std::vector<int>> src2{{1,4},{4,5}};
    ASSERT_EQ(res2, mergeSimple(src2));
    std::vector<std::vector<int>> src3{{1,4},{1, 4}};
    ASSERT_EQ(res3, mergeSimple(src3));
    std::vector<std::vector<int>> src4{{1,4},{2, 3}};
    ASSERT_EQ(res4, mergeSimple(src4));
}
