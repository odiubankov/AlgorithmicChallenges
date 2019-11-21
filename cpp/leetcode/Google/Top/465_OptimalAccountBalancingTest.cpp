#include "465_OptimalAccountBalancing.h"
#include <gtest/gtest.h>

TEST(OptimalAccountBalancing, test) {
    ASSERT_EQ(minTransfers({{0,1,10}, {2,0,5}}), 2);
    ASSERT_EQ(minTransfers({{0,1,10}, {1,0,1}, {1,2,5}, {2,0,5}}), 1);
}

TEST(OptimalAccountBalancing, test2) {
    ASSERT_EQ(minTransfers({{10,11,6},{12,13,7},{14,15,2},{14,16,2},{14,17,2},{14,18,2}}), 6);
}

TEST(OptimalAccountBalancing, test3) {
    ASSERT_EQ(minTransfers({{1,5,8},{8,9,8},{2,3,9},{4,3,1}}), 4);
}

TEST(OptimalAccountBalancing, test4) {
    ASSERT_EQ(minTransfers({{1,2,3},{1,3,3},{6,4,1},{5,4,4}}), 4);
}
