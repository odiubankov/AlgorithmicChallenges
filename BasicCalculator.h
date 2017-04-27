// https://leetcode.com/problems/basic-calculator-ii/#/description
/*
Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces.
The integer division should truncate toward zero.
You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
*/
#ifndef LEETCODESOLUTIONS_BASICCALCULATOR_H
#define LEETCODESOLUTIONS_BASICCALCULATOR_H

#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

namespace basiccalc
{
class Solution {
    int getOperand(const string& s, int& i)
    {
        for (;i < static_cast<int>(s.size()); ++i)
            if (s[i] != ' ')
                break;

        string result{s[i++]};
        for (;i < static_cast<int>(s.size()); ++i)
            if (isdigit(s[i]))
                result.append(1, s[i]);
            else
                break;

        return atoi(result.c_str());
    }

    char getOperator(const string& s, int& i)
    {
        for (;i < static_cast<int>(s.size()); ++i)
            if (s[i] != ' ')
                return s[i++];

        return ' ';
    }

public:
    int calculate(string s) {
        vector<int> operands;
        vector<bool> operators;
        int i = 0;
        operands.push_back(getOperand(s, i));
        while(i < static_cast<int>(s.size()))
        {
            auto oper = getOperator(s, i);
            switch (oper) {
                case '*':
                    *operands.rbegin() = *operands.rbegin() *  getOperand(s, i);
                    break;
                case '/':
                    *operands.rbegin() = *operands.rbegin() / getOperand(s, i);
                    break;
                case '+':
                    operands.push_back(getOperand(s, i));
                    operators.push_back(true);
                    break;
                case '-':
                    operands.push_back(getOperand(s, i));
                    operators.push_back(false);
                    break;
                default:break;
            }
        }

        if (operands.size() == 1)
        {
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
        while (operandIt != end(operands))
        {
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
}//namespace basiccalc

#endif //LEETCODESOLUTIONS_BASICCALCULATOR_H
