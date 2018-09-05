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

}

