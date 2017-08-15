/*
* Hash Tables: Ransom Note
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

#ifndef HACKERRANK_HASHTABLESRANSOMNOTE_H
#define HACKERRANK_HASHTABLESRANSOMNOTE_H

#include <vector>
#include <string>
#include <unordered_map>

namespace hackerrank
{

bool ransom_note(std::vector<std::string> magazine, std::vector<std::string> ransom)
{
    std::unordered_map<std::string, unsigned> magazineWords;
    for (const auto &word: magazine) {
        auto insertRes = magazineWords.emplace(word, 1);
        if (!insertRes.second) {
            ++(insertRes.first->second);
        }
    }

    for (const auto &word : ransom) {
        auto magazineIt = magazineWords.find(word);
        if (magazineIt == end(magazineWords) || magazineIt->second == 0)
            return false;
        --(magazineIt->second);
    }

    return true;
}

}//namespace hackerrank

#endif //HACKERRANK_HASHTABLESRANSOMNOTE_H
