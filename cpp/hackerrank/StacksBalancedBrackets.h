/**
* Stacks: Balanced Brackets
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

#ifndef HACKERRANK_STACKSBALANCEDBRACKETS_H
#define HACKERRANK_STACKSBALANCEDBRACKETS_H

#include <stack>
#include <string>

namespace hackerrank
{

bool is_balanced(std::string expression)
{
    std::stack<char> openedBrackets;
    for (const auto &character : expression) {
        switch (character) {
            case '(':
            case '[':
            case '{':openedBrackets.push(character);
                break;
            case ')':
                if (openedBrackets.empty() || openedBrackets.top() != '(')
                    return false;
                openedBrackets.pop();
                break;
            case '}':
                if (openedBrackets.empty() || openedBrackets.top() != '{')
                    return false;
                openedBrackets.pop();
                break;
            case ']':
                if (openedBrackets.empty() || openedBrackets.top() != '[')
                    return false;
                openedBrackets.pop();
                break;
            default:break;
        }
    }

    return openedBrackets.empty();
}

}//namespace hackerrank

#endif //HACKERRANK_STACKSBALANCEDBRACKETS_H
