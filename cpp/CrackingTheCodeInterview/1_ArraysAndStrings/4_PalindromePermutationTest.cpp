#include "4_PalindromePermutation.h"

#include <gtest/gtest.h>

TEST(PalindromePermutation, NotPalindrome) {
    ASSERT_FALSE(isPalindromePermutation("abc"));
}

TEST(PalindromePermutation, Palindrome) {
    ASSERT_TRUE(isPalindromePermutation("caabb"));
}