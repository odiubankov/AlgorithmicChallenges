#include "1057_CampusBikes.h"
#include <gtest/gtest.h>

TEST(CampusBikes, test) {
    std::vector<int> res{1,0};
    ASSERT_EQ(res,assignBikes({{0,0},{2,1}}, {{1,2},{3,3}}));
    std::vector<int> res2{0,2,1};
    ASSERT_EQ(res2,assignBikes({{0,0},{1,1}, {2,0}}, {{1,0},{2,2},{2,1}}));
}

TEST(CampusBikes, test2) {
    std::vector<int> res{1,0};
    ASSERT_EQ(res,assignBikesBucketSort({{0,0},{2,1}}, {{1,2},{3,3}}));
    std::vector<int> res2{0,2,1};
    ASSERT_EQ(res2,assignBikesBucketSort({{0,0},{1,1}, {2,0}}, {{1,0},{2,2},{2,1}}));
}
