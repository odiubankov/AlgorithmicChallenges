#include "837_New21Game.h"
#include <gtest/gtest.h>
#include <cmath>

TEST(New21Game, test) {
    ASSERT_DOUBLE_EQ(1.0, new21Game(10, 1, 10));
}

TEST(New21Game, test2) {
    ASSERT_DOUBLE_EQ(0.6, new21Game(6, 1, 10));
}

TEST(New21Game, test3) {
//    ASSERT_TRUE(abs(0.73278 - new21Game(21, 17, 10)) < 0.00001 );
    ASSERT_TRUE(abs(0.73278 - new21GameDP(21, 17, 10)) < 0.00001 );
//    ASSERT_DOUBLE_EQ(0.73278, new21GameDP(21, 17, 10));
//    ASSERT_DOUBLE_EQ(0.73278, new21GameCorrect(21, 17, 10));
}

TEST(New21Game, test4) {
    ASSERT_DOUBLE_EQ(1.0, new21Game(0, 0, 1));
}
