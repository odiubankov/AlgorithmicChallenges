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

using StrItT = std::string::const_iterator;

void expandAroundCenter(
        const StrItT& leftIt, const StrItT& rightIt,
        const StrItT& beginIt, const StrItT& endIt,
        string& longestPalindrome) {
    auto left = leftIt;
    auto right = rightIt;
    while (left != beginIt && (right + 1) != endIt && *(left - 1) == *(right + 1)) {
        --left;
        ++right;
    }
    if ((std::distance(left, right + 1)) > longestPalindrome.length()) {
        longestPalindrome = std::string{left, right + 1};
    }
}

string longestPalindromeCenterExpand(const string& s) {
    if (s.empty())
        return "";
    string longestPalindrome{s.front()};
    for (auto it = begin(s) + 1; it != end(s); ++it) {
        //even cnt
        auto leftIt = it - 1;
        if ((it + 1) != end(s) && *(it - 1) == *(it + 1)) {
            expandAroundCenter(it - 1, it + 1, begin(s), end(s), longestPalindrome);
        }
        //odd cnt
        if (*(it - 1) == (*it)) {
            expandAroundCenter(it - 1, it, begin(s), end(s), longestPalindrome);
        }
    }
    return longestPalindrome;
}

#endif //ALGORITHMICCHALLENGES_5_LONGESTPALINDROMICSUBSTRING_H
