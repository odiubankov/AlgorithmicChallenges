#include "1153_StringTransformsIntoAnotherString.h"
#include <gtest/gtest.h>

TEST(StringTransform, test) {
    ASSERT_FALSE(canConvert("leetcode", "codeleet"));
}

TEST(StringTransform, test2) {
    ASSERT_FALSE(canConvert("abcdefghijklmnopqrstuvwxyz", "bcdefghijklmnopqrstuvwxyza"));
}

TEST(StringTransform, test3) {
    ASSERT_TRUE(canConvert("abcdefghijklmnopqrstuvwxyz",
                           "bcdefghijklmnopqrstuvwxyzq"));
}
