/**
* https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
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

#ifndef LEETCODESOLUTIONS_LONGESTUNIQCHARSSUBSTR_H
#define LEETCODESOLUTIONS_LONGESTUNIQCHARSSUBSTR_H

#include <string>
#include <unordered_set>

namespace leetcode
{

class Solution
{
public:
    std::size_t lengthOfLongestSubstring(std::string s)
    {
        std::size_t longestSubstrLength = 0;
        std::unordered_set<char> substrChars;
        auto substrBeginIt = begin(s);
        auto substrEndIt = begin(s);
        for (; substrEndIt != end(s); ++substrEndIt) {
            auto insertRes = substrChars.insert(*substrEndIt);
            if (!insertRes.second) {
                if (static_cast<int>(substrChars.size()) > longestSubstrLength) {
                    longestSubstrLength = substrChars.size();
                }

                while (*substrBeginIt != *substrEndIt) {
                    substrChars.erase(*substrBeginIt);
                    ++substrBeginIt;
                }

                ++substrBeginIt;
            }
        }

        if (static_cast<int>(substrChars.size()) > longestSubstrLength) {
            return substrChars.size();
        }

        return longestSubstrLength;
    }
};

}//leetcode

#endif //LEETCODESOLUTIONS_LONGESTUNIQCHARSSUBSTR_H
