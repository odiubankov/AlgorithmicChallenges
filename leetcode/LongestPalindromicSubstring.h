/**
* https://leetcode.com/problems/longest-palindromic-substring/#/description
*
* Copyright 2017 Oleksii Diubankov
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef LEETCODESOLUTIONS_LONGESTPALINDROMICSUBSTRING_H
#define LEETCODESOLUTIONS_LONGESTPALINDROMICSUBSTRING_H

#include <string>
#include <vector>


namespace leetcode
{

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        unsigned long longestPalindromeBegin = 0;
        unsigned long longestPalindromeLength = 1;
        std::vector<unsigned long> palindromes{1};
        for (long i = 1; i < static_cast<long>(s.size()); ++i) {
            for (auto palindromeIt = begin(palindromes); palindromeIt != end(palindromes);) {
                long newIndex = i - *palindromeIt - 1;
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

}//namespace leetcode

#endif //LEETCODESOLUTIONS_LONGESTPALINDROMICSUBSTRING_H
