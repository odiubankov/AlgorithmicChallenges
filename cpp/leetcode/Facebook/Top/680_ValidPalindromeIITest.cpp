#include "680_ValidPalindromeII.h"
#include <gtest/gtest.h>

TEST(ValidPalindromeII, test) {
    ASSERT_TRUE(validPalindrome("abca"));
}

TEST(ValidPalindromeII, test2) {
    ASSERT_TRUE(validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"));
}
