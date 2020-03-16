#include "1066_CampusBikesII.h"
#include <gtest/gtest.h>

TEST(CampusBikes2, test) {
    ASSERT_EQ(6, assignBikes2({{0,0},{2,1}}, {{1,2},{3,3}}));
    ASSERT_EQ(6, assignBikesPriorityQueue({{0,0},{2,1}}, {{1,2},{3,3}}));
}

TEST(CampusBikes2, test2) {
    ASSERT_EQ(4, assignBikes2({{0,0},{1,1},{2,0}}, {{1,0},{2,2},{2,1}}));
    ASSERT_EQ(4, assignBikesPriorityQueue({{0,0},{1,1},{2,0}}, {{1,0},{2,2},{2,1}}));
}
