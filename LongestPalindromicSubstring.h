#ifndef LEETCODESOLUTIONS_LONGESTPALINDROMICSUBSTRING_H
#define LEETCODESOLUTIONS_LONGESTPALINDROMICSUBSTRING_H

#include <string>
#include <vector>
#include <list>

using namespace std;

namespace longestpalindromicsubstr
{
  class Solution {
  public:
    string longestPalindrome(string s)
    {
      short longestPalindromeBegin = 0;
      short longestPalindromeLength = 1;
      vector<short> palindromes{1};
      for (short i = 1; i < s.size(); ++i)
      {
        for (auto palindromeIt = begin(palindromes); palindromeIt != end(palindromes);)
        {
          int newIndex = i - *palindromeIt - 1;
          if (newIndex >= 0 && s[i] == s[newIndex])
          {
            *palindromeIt += 2;
            ++palindromeIt;
          }
          else
          {
            if (*palindromeIt > longestPalindromeLength)
            {
              longestPalindromeLength = *palindromeIt;
              longestPalindromeBegin = i - *palindromeIt;
            }

            palindromeIt = palindromes.erase(palindromeIt);
          }
        }

        if (s[i] == s[i - 1])
        {
          palindromes.push_back(2);
        }

        palindromes.push_back(1);
      }

      if (*begin(palindromes) > longestPalindromeLength)
      {
        return s.substr(s.size() - *begin(palindromes), *begin(palindromes));
      }

      return s.substr(longestPalindromeBegin, longestPalindromeLength);
    }
  };
}

#endif //LEETCODESOLUTIONS_LONGESTPALINDROMICSUBSTRING_H
