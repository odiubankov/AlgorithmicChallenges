#include "../LegoBlocks.h"
#include <gtest/gtest.h>

namespace hackerrank {

TEST(LegoBlocks, test1) {
    ASSERT_EQ(getStableWallCnt(2, 2), 3);
}

TEST(LegoBlocks, test2) {
    ASSERT_EQ(getStableWallCnt(2, 3), 7);
}

TEST(LegoBlocks, test3) {
    ASSERT_EQ(getStableWallCnt(3, 2), 9);
}

TEST(LegoBlocks, test4) {
    ASSERT_EQ(getStableWallCnt(4, 4), 3375);
}

TEST(LegoBlocks, test5) {
    ASSERT_EQ(getStableWallCnt(3, 7), 16129);
}

TEST(LegoBlocks, test6) {
    ASSERT_EQ(getStableWallCnt(8, 3), 328650);
}

TEST(LegoBlocks, test7) {
    ASSERT_EQ(getStableWallCnt(7, 4), 5562914);
}

TEST(LegoBlocks, test8) {
    ASSERT_EQ(getStableWallCnt(6, 8), 402844528);
}

}

