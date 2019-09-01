#include "5_OneAway.h"

#include <gtest/gtest.h>

TEST(OneAway, OneReplace) {
    ASSERT_TRUE(isOneAway("abc", "acc"));
}

TEST(OneAway, OneRemove) {
    ASSERT_TRUE(isOneAway("abcd", "acd"));
}

TEST(OneAway, OneAdd) {
    ASSERT_TRUE(isOneAway("abc", "abbc"));
}

TEST(OneAway, TwoRemove) {
    ASSERT_FALSE(isOneAway("abc", "a"));
}

TEST(OneAway, TwoAdd) {
    ASSERT_FALSE(isOneAway("abcd", "cd"));
}

TEST(OneAway, OneExtra) {
    ASSERT_FALSE(isOneAway("abc", "b"));
}

