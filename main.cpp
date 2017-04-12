#include <iostream>
#include <assert.h>
#include "LongestPalindromicSubstring.h"

int main() {
    longestpalindromicsubstr::Solution solution;
    assert("aabaa" == solution.longestPalindrome("aabaa"));
    assert("bbb" == solution.longestPalindrome("aabbb"));
    assert("bb" == solution.longestPalindrome("cbbd"));
    assert("anana" == solution.longestPalindrome("bananas"));
    assert("anana" == solution.longestPalindrome("bananas"));
    assert("aaabaaa" == solution.longestPalindrome("aaabaaaa"));
    return 0;
}