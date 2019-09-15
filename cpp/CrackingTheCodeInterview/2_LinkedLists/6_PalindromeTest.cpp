#include "6_Palindrome.h"
#include <gtest/gtest.h>

TEST(Palindrome, notPalindromeEven) {
    ASSERT_FALSE(isPalindrome(createList({1, 2})));
}

TEST(Palindrome, palindromeEven) {
    ASSERT_FALSE(isPalindrome(createList({1, 2, 2, 1})));
}

TEST(Palindrome, notPalindromeOdd) {
    ASSERT_FALSE(isPalindrome(createList({1, 2, 3})));
}

TEST(Palindrome, palindromeOdd) {
    ASSERT_FALSE(isPalindrome(createList({1, 2, 5,  2, 1})));
}

TEST(Palindrome, empty){
    ASSERT_TRUE(isPalindrome(nullptr));
}

TEST(Palindrome, oneElement){
    ASSERT_TRUE(isPalindrome(createList({10})));
}
