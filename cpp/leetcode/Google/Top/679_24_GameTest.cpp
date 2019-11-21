#include "679_24_Game.h"
#include <gtest/gtest.h>

TEST(Game24, test) {
    ASSERT_TRUE(judgePoint24({3, 3, 8, 8}));
}

TEST(Game24, test2) {
    ASSERT_FALSE(judgePoint24({1, 2, 1, 2}));
}
