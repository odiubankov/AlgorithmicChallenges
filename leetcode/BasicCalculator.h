/**
* https://leetcode.com/problems/basic-calculator-ii/#/description
*
* Implement a basic calculator to evaluate a simple expression string.
* The expression string contains only non-negative integers, +, -, *, / operators and empty spaces.
* The integer division should truncate toward zero.
* You may assume that the given expression is always valid.
*
* Some examples:
* "3+2*2" = 7
* " 3/2 " = 1
* " 3+5 / 2 " = 5
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

#ifndef LEETCODESOLUTIONS_BASICCALCULATOR_H
#define LEETCODESOLUTIONS_BASICCALCULATOR_H

#include <string>
#include <vector>
#include <cstdlib>

namespace leetcode
{

class Solution
{
    long getOperand(const std::string &s, int &i)
    {
        for (; i < static_cast<int>(s.size()); ++i)
            if (s[i] != ' ')
                break;

        std::string result{s[i++]};
        for (; i < static_cast<int>(s.size()); ++i)
            if (isdigit(s[i]) != 0)
                result.append(1, s[i]);
            else
                break;

        return strtol(result.c_str(), nullptr, 10);
    }

    char getOperator(const std::string &s, int &i)
    {
        for (; i < static_cast<int>(s.size()); ++i)
            if (s[i] != ' ')
                return s[i++];

        return ' ';
    }

public:
    long calculate(const std::string &s)
    {
        std::vector<long> operands;
        std::vector<bool> operators;
        int i = 0;
        operands.push_back(getOperand(s, i));
        while (i < static_cast<int>(s.size())) {
            auto oper = getOperator(s, i);
            switch (oper) {
                case '*':*operands.rbegin() = *operands.rbegin() * getOperand(s, i);
                    break;
                case '/':*operands.rbegin() = *operands.rbegin() / getOperand(s, i);
                    break;
                case '+':operands.push_back(getOperand(s, i));
                    operators.push_back(true);
                    break;
                case '-':operands.push_back(getOperand(s, i));
                    operators.push_back(false);
                    break;
                default:break;
            }
        }

        if (operands.size() == 1) {
            return operands.front();
        }

        auto operandIt = begin(operands);
        auto result = *operandIt;
        ++operandIt;
        auto operatorIt = begin(operators);
        if (*operatorIt) {
            result += *operandIt;
        }
        else {
            result -= *operandIt;
        }

        ++operatorIt;
        ++operandIt;
        while (operandIt != end(operands)) {
            if (*operatorIt) {
                result += *operandIt;
            }
            else {
                result -= *operandIt;
            }

            ++operandIt;
            ++operatorIt;
        }

        return result;
    }
};

}//namespace leetcode

#endif //LEETCODESOLUTIONS_BASICCALCULATOR_H
