//https://leetcode.com/problems/longest-palindromic-substring/
#ifndef ALGORITHMICCHALLENGES_5_LONGESTPALINDROMICSUBSTRING_H
#define ALGORITHMICCHALLENGES_5_LONGESTPALINDROMICSUBSTRING_H

#include <string>
using namespace std;

using StrItT = string::const_iterator;

string growPalindrome(StrItT leftIt, StrItT rightIt, StrItT beginIt, StrItT endIt) {
    auto palindromeStart = leftIt, palindromeEnd = leftIt + 1;
    for (; rightIt != endIt && *leftIt == *rightIt;
         --leftIt, ++rightIt) {
        palindromeStart = leftIt;
        palindromeEnd = rightIt + 1;
        if (leftIt == beginIt)
            break;
    }
    return string{palindromeStart, palindromeEnd};
}

void setLongestPalindrome(string& longestPalindrome, string palindrome) {
    if (palindrome.length() > longestPalindrome.length())
        longestPalindrome = move(palindrome);
}

string longestPalindrome(const string& s) {
    if (s.empty())
        return "";
    auto sIt = begin(s);
    string longestPalindrome = growPalindrome(sIt, sIt + 1, begin(s), end(s));
    ++sIt;
    for (; distance(sIt, end(s)) > longestPalindrome.length() / 2; ++sIt) {
        setLongestPalindrome(longestPalindrome, growPalindrome(sIt, sIt + 1, begin(s), end(s)));
        setLongestPalindrome(longestPalindrome, growPalindrome(sIt - 1, sIt + 1, begin(s), end(s)));
    }
    return longestPalindrome;
}

#endif //ALGORITHMICCHALLENGES_5_LONGESTPALINDROMICSUBSTRING_H
