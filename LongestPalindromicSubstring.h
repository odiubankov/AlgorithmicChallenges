// https://leetcode.com/problems/longest-palindromic-substring/#/description

#ifndef LEETCODESOLUTIONS_LONGESTPALINDROMICSUBSTRING_H
#define LEETCODESOLUTIONS_LONGESTPALINDROMICSUBSTRING_H

#include <string>
#include <vector>

using namespace std;

namespace longestpalindromicsubstr
{
class Solution
{
public:
    string longestPalindrome(string s)
    {
        long longestPalindromeBegin = 0;
        long longestPalindromeLength = 1;
        vector<long> palindromes{1};
        for (long i = 1; i < static_cast<long>(s.size()); ++i) {
            for (auto palindromeIt = begin(palindromes); palindromeIt != end(palindromes);) {
                auto newIndex = i - *palindromeIt - 1;
                if (newIndex >= 0 && s[i] == s[newIndex]) {
                    *palindromeIt += 2;
                    ++palindromeIt;
                }
                else {
                    if (*palindromeIt > longestPalindromeLength) {
                        longestPalindromeLength = *palindromeIt;
                        longestPalindromeBegin = i - *palindromeIt;
                    }

                    palindromeIt = palindromes.erase(palindromeIt);
                }
            }

            if (s[i] == s[i - 1]) {
                palindromes.push_back(2);
            }

            palindromes.push_back(1);
        }

        if (*begin(palindromes) > longestPalindromeLength) {
            return s.substr(s.size() - *begin(palindromes), *begin(palindromes));
        }

        return s.substr(longestPalindromeBegin, longestPalindromeLength);
    }
};
}

#endif //LEETCODESOLUTIONS_LONGESTPALINDROMICSUBSTRING_H
