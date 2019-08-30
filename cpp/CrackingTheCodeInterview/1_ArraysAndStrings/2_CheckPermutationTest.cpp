#include "2_CheckPermutation.h"
#include <gtest/gtest.h>

TEST(CheckPermutation, DifferentLength)
{
    ASSERT_FALSE(checkPermutation("a", "aa"));
}

TEST(CheckPermutation, NoPermutation)
{
    ASSERT_FALSE(checkPermutation("abc", "abd"));
}

TEST(CheckPermutation, Permutation)
{
    ASSERT_TRUE(checkPermutation("abc", "cba"));
}