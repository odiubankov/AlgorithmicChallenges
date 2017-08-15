/**
* Strings: Making Anagrams
*
* Cracking the Coding Interview Challenges
* https://www.hackerrank.com/domains/tutorials/cracking-the-coding-interview
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

#ifndef HACKERRANK_STRINGSMAKINGANAGRAMS_H
#define HACKERRANK_STRINGSMAKINGANAGRAMS_H

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

namespace hackerrank
{

int number_needed(std::string a, std::string b)
{
    std::vector<int> characters('z' - 'a' + 1, 0);
    for (const auto &character : a) {
        ++characters[character - 'a'];
    }

    for (const auto &character : b) {
        --characters[character - 'a'];
    }

    int result = 0;
    for (const auto &diff : characters) {
        result += abs(diff);
    }

    return result;
}

}//namespace hackerrank

#endif //HACKERRANK_STRINGSMAKINGANAGRAMS_H
