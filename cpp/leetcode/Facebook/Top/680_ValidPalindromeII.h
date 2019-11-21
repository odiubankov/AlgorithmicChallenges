//https://leetcode.com/problems/valid-palindrome-ii/
#ifndef ALGORITHMICCHALLENGES_680_VALIDPALINDROMEII_H
#define ALGORITHMICCHALLENGES_680_VALIDPALINDROMEII_H

#include <string>
using namespace std;

bool validPalindromeImpl(const string& s, size_t left, size_t right, bool allowErrors) {
    for (size_t l = left, r = right; l < right; ++l, --r) {
        if (s[l] != s[r]) {
            if (!allowErrors)
                return false;
            return validPalindromeImpl(s, l + 1, r, false) ||
                    validPalindromeImpl(s, l, r - 1, false);
        }
    }
    return true;
}

bool validPalindrome(const string& s) {
    return validPalindromeImpl(s, 0, s.size() - 1, true);
}

#endif //ALGORITHMICCHALLENGES_680_VALIDPALINDROMEII_H
