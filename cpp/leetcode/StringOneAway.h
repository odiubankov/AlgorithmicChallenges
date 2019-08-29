/**
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

#ifndef LEETCODESOLUTIONS_STRINGONEAWAY_H
#define LEETCODESOLUTIONS_STRINGONEAWAY_H

#include <string>
#include <array>
#include <unordered_set>
#include <cmath>
#include <limits>

namespace strpermutation
{
    constexpr size_t getCharIndex(char character) noexcept
    {
        return static_cast<std::size_t>(character - std::numeric_limits<char>::min());
    }


    bool isOneAway(const std::string& str1, const std::string& str2)
    {
        constexpr auto ansiSize = static_cast<std::size_t>(std::numeric_limits<char>::max() - std::numeric_limits<char>::min());
        std::array<int, ansiSize> ansiChars{};
        for (auto& val : ansiChars)
            val = 0;

        for(const auto& character : str1)
        {
            const auto index = getCharIndex(character);
            ++ansiChars[index];
        }

        for(const auto& character : str2)
        {
            const auto index = getCharIndex(character);
            --ansiChars[index];
        }

        std::unordered_set<char> uniqueChars(cbegin(str1), cend(str1));
        std::copy(cbegin(str2), cend(str2), std::inserter(uniqueChars, begin(uniqueChars)));
        std::size_t oneCharPermutationsCnt = 0;
        for (const auto& character : uniqueChars)
        {
            const auto index = getCharIndex(character);
            if (ansiChars[index] != 0)
            {
                if (ansiChars[index] > 1 || ansiChars[index] < -1)
                    return false;

                ++oneCharPermutationsCnt;
                if (oneCharPermutationsCnt > 2)
                    return false;
            }
        }

        return true;
    }
}

#endif //LEETCODESOLUTIONS_STRINGONEAWAY_H
