#include "6_StringCompression.h"

#include <gtest/gtest.h>

TEST(StringCompression, aabcccccaaa) {
    ASSERT_EQ(compressString("aabcccccaaa"), "a2b1c5a3");
}

TEST(StringCompression, aa) {
    ASSERT_EQ(compressString("aa"), "aa");
}

TEST(StringCompression, bbbcd) {
    ASSERT_EQ(compressString("bbbcd"), "bbbcd");
}
