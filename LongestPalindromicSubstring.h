#ifndef LEETCODESOLUTIONS_LONGESTPALINDROMICSUBSTRING_H
#define LEETCODESOLUTIONS_LONGESTPALINDROMICSUBSTRING_H

#include <string>

using namespace std;

namespace longestpalindromicsubstr
{
    class Solution {
    public:
        string longestPalindrome(string s)
        {
            string longestPalindrome = {s[0]};
            int palindromeCenterSize = 1;
            bool inCenter = true;
            int currentPalindromeLength = 1;
            for (int i = 1; i < s.size(); ++i)
            {
                if (inCenter)
                {
                    if (s[i] == s[i-1])
                    {
                        ++currentPalindromeLength;
                    }
                    else
                    {
                        palindromeCenterSize = currentPalindromeLength;
                        inCenter = false;
                    }
                }

                if (!inCenter)
                {
                    int palindromeBegin = i - (currentPalindromeLength + 1 - palindromeCenterSize) * 2 - (palindromeCenterSize - 1);
                    if (palindromeBegin > 0 && s[i] == s[palindromeBegin])
                    {
                        ++currentPalindromeLength;
                    }
                    else
                    {
                        if (currentPalindromeLength > longestPalindrome.size())
                        {
                            longestPalindrome = s.substr(palindromeBegin + 1, i);
                        }

                        inCenter = true;
                        currentPalindromeLength = 1;
                        palindromeCenterSize = 1;
                    }
                }
            }

            return longestPalindrome;
        }
    };
}

#endif //LEETCODESOLUTIONS_LONGESTPALINDROMICSUBSTRING_H
