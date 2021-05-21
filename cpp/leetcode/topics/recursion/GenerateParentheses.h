/**
* https://leetcode.com/problems/generate-parentheses/#/description
*
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*
*For example, given n = 3, a solution set is:
* [
*  "((()))",
*  "(()())",
*  "(())()",
*  "()(())",
*  "()()()"
* ]
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

#ifndef LEETCODESOLUTIONS_GENERATEPARENTHESES_H
#define LEETCODESOLUTIONS_GENERATEPARENTHESES_H

#include <vector>
#include <string>
#include <iterator>

namespace leetcode
{

class Solution
{
    std::vector<std::string> getNext(const std::string &currentString, int leftToOpen, int leftToClose)
    {
        std::vector<std::string> nextStrings;
        if (leftToOpen > 0) {
            nextStrings = getNext(currentString + "(", leftToOpen - 1, leftToClose + 1);
        }

        if (leftToClose > 0) {
            auto nextStrings2 = getNext(currentString + ")", leftToOpen, leftToClose - 1);
            std::move(begin(nextStrings2), end(nextStrings2), back_inserter(nextStrings));
        }
        else {
            if (leftToOpen == 0) {
                return {currentString};
            }
        }

        return nextStrings;
    }

public:
    std::vector<std::string> generateParenthesis(int n)
    {
        return getNext("(", n - 1, 1);
    }
};

}//namespace leetcode

#endif //LEETCODESOLUTIONS_GENERATEPARENTHESES_H
