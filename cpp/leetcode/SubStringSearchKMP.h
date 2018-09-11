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

#ifndef LEETCODESOLUTIONS_SUBSTRINGSEARCHKMP_H
#define LEETCODESOLUTIONS_SUBSTRINGSEARCHKMP_H

#include <string>
#include <vector>

namespace leetcode
{

std::vector<int> getLongestSuffixPrefixes(const std::string &world)
{
    std::vector<int> lsp(world.length(), 0);
    int length = 0;
    for (int i = 1; i < world.length();) {
        if (world[i] == world[length])
            lsp[i++] = ++length;
        else if (length > 0)
            length = lsp[length - 1];
        else
            lsp[i++] = 0;
    }

    return lsp;
}

int findSubstring(const std::string &str, const std::string &word)
{
    if (word.empty())
        return 0;

    if (word.length() > str.length())
        return -1;

    auto lsp = getLongestSuffixPrefixes(word);
    int equalCharsCnt = 0;
    int wordStart = 0;
    while (wordStart + equalCharsCnt < str.length()) {
        if (str[wordStart + equalCharsCnt] == word[equalCharsCnt]) {
            ++equalCharsCnt;
            if (equalCharsCnt == word.length())
                return wordStart;
        }
        else {
            if (equalCharsCnt == 0) {
                ++wordStart;
            }
            else {
                wordStart = wordStart + equalCharsCnt - lsp[equalCharsCnt - 1];
                equalCharsCnt = lsp[equalCharsCnt - 1];
            }
        }
    }

    return -1;
}

}//namespace leetcode

#endif //LEETCODESOLUTIONS_SUBSTRINGSEARCHKMP_H
