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
#include <sstream>
using namespace std;

namespace leetcode
{

inline constexpr char toUpperDiff() noexcept {
    return 'A' - 'a';
}

inline constexpr bool isLowerCase(char character) noexcept {
    return character >= 'a' && character <= 'z';
}

class Solution
{
public:
    const char Separator = '-';
    char toUpper(char c) {
        return isLowerCase(c) ? c + toUpperDiff() : c;
    }
    string licenseKeyFormatting(const string& S, const int K) {
        stringstream ss;
        int currentGroupCnt = 0;
        for (auto sIt = rbegin(S); sIt != rend(S); ++sIt) {
            if (*sIt != Separator) {
                if (currentGroupCnt == K) {
                    ss << Separator;
                    currentGroupCnt = 0;
                }
                ss << toUpper(*sIt);
                ++currentGroupCnt;
            }
        }
        auto res = ss.str();
        reverse(begin(res), end(res));
        return res;
    }
};

}//namespace leetcode

#endif //LEETCODESOLUTIONS_LICENSEKEYFORMATTING_H
