// https://leetcode.com/problems/license-key-formatting/#/description

#ifndef LEETCODESOLUTIONS_LICENSEKEYFORMATTING_H
#define LEETCODESOLUTIONS_LICENSEKEYFORMATTING_H

#include <string>
#include <algorithm>

using namespace std;

namespace licensekeyformatting
{
    inline constexpr char toUpperDiff() noexcept
    {
        return 'A' - 'a';
    }

    inline constexpr bool isLowerCase(char character) noexcept
    {
        return character >= 'a' && character <= 'z';
    }

    class Solution {
    public:
        string licenseKeyFormatting(string S, int K)
        {
            string result;
            int currentGroupCnt = 0;
            auto i = S.size();
            do
            {
                --i;
                if (currentGroupCnt == K)
                {
                    result.push_back('-');
                    currentGroupCnt = 0;
                }

                if (S[i] == '-')
                {
                    continue;
                }

                if (isLowerCase(S[i]))
                {
                    result.push_back(S[i] + toUpperDiff());
                }
                else
                {
                    result.push_back(S[i]);
                }

                ++currentGroupCnt;
            } while (i > 0);

            result.erase(result.find_last_not_of("-") + 1);
            reverse(begin(result), end(result));
            return result;
        }
    };
}

#endif //LEETCODESOLUTIONS_LICENSEKEYFORMATTING_H
