#include "659_SplitArrayIntoConsecutiveSubsequences.h"
#include <gtest/gtest.h>

TEST(SplitArray, test) {
    ASSERT_TRUE(isPossible({1,2,3,3,4,5}));
}

TEST(SplitArray, test2) {
    ASSERT_TRUE(isPossible({1,2,3,3,4,4,5,5}));
}

TEST(SplitArray, test3) {
    ASSERT_FALSE(isPossible({1,2,3,4,4,5}));
}
