#include "773_SlidingPuzzle.h"
#include <gtest/gtest.h>

TEST(SlidingPuzzle, test) {
    ASSERT_EQ(1, slidingPuzzle({{1, 2, 3}, {4, 0, 5}}));
}

TEST(SlidingPuzzle, test2) {
    ASSERT_EQ(-1, slidingPuzzle({{1, 2, 3}, {5, 4, 0}}));
}

TEST(SlidingPuzzle, test3) {
    ASSERT_EQ(5, slidingPuzzle({{4, 1, 2}, {5, 0, 3}}));
}