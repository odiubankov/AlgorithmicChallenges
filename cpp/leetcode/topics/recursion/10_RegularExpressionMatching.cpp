#include "10_RegularExpressionMatching.h"
#include <gtest/gtest.h>

TEST(RegExp, test) {
    ASSERT_TRUE(isMatch("bccbbabcaccacbcacaa", ".*b.*c*.*.*.c*a*.c"));
}
