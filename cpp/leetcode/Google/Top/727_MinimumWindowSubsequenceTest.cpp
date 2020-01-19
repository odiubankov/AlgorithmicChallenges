#include "727_MinimumWindowSubsequence.h"
#include <gtest/gtest.h>

TEST(MinimumWindowSubsequence4, test) {
    ASSERT_EQ("bcde", minWindowSlidingWindow("abcdebdde", "bde"));
}