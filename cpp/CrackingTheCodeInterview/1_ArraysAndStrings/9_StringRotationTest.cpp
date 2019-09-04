#include "9_StringRotation.h"

#include <gtest/gtest.h>

TEST(StringRotation, Rotation) {
    ASSERT_TRUE(rotateString("abcde", "cdeab"));
}

TEST(StringRotation, NotRotation) {
    ASSERT_FALSE(rotateString("abcde", "abced"));
}

TEST(StringRotation, DifferentLength) {
    ASSERT_FALSE(rotateString("a", "aa"));
}
