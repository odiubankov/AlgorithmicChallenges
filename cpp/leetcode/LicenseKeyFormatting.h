/**
* https://leetcode.com/problems/license-key-formatting/#/description
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

#ifndef LEETCODESOLUTIONS_LICENSEKEYFORMATTING_H
#define LEETCODESOLUTIONS_LICENSEKEYFORMATTING_H

#include <string>
#include <algorithm>

namespace leetcode
{

inline constexpr char toUpperDiff() noexcept
{
    return 'A' - 'a';
}

inline constexpr bool isLowerCase(char character) noexcept
{
    return character >= 'a' && character <= 'z';
}

class Solution
{
public:
    std::string licenseKeyFormatting(std::string S, int K)
    {
        std::string result;
        int currentGroupCnt = 0;
        auto i = S.size();
        do {
            --i;
            if (currentGroupCnt == K) {
                result.push_back('-');
                currentGroupCnt = 0;
            }

            if (S[i] == '-') {
                continue;
            }

            if (isLowerCase(S[i])) {
                result.push_back(S[i] + toUpperDiff());
            }
            else {
                result.push_back(S[i]);
            }

            ++currentGroupCnt;
        }
        while (i > 0);

        result.erase(result.find_last_not_of('-') + 1);
        reverse(begin(result), end(result));
        return result;
    }
};

}//namespace leetcode

#endif //LEETCODESOLUTIONS_LICENSEKEYFORMATTING_H
