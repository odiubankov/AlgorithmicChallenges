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
#include <functional>
#include <vector>

using namespace std;

namespace basiccalc
{
class Solution {
    int getOperand(const string& s, int& i)
    {
        for (;i < s.size(); ++i)
            if (s[i] != ' ')
                break;

        string result{s[i++]};
        for (;i < s.size(); ++i)
            if (isdigit(s[i]))
                result.append(1, s[i]);
            else
                break;

        return atoi(result.c_str());
    }

    char getOperator(const string& s, int& i)
    {
        for (;i < s.size(); ++i)
            if (s[i] != ' ')
                return s[i++];

        return ' ';
    }

public:
    int calculate(string s) {
        vector<int> operands;
        vector<function<int(int, int)>> operators;
        int i = 0;
        operands.push_back(getOperand(s, i));
        while(i < s.size())
        {
            auto oper = getOperator(s, i);
            if (oper == '*')
            {
                *operands.rend() = *operands.rend() *  getOperand(s, i);
            }
            else if (oper == '/')
            {
                *operands.rend() = *operands.rend() / getOperand(s, i);
            }
            else if (oper == '+')
            {
                operands.push_back(getOperand(s, i));
                operators.push_back([](int a, int b){ return a+ b;});
            }
            else
            {
                operands.push_back(getOperand(s, i));
                operators.push_back([](int a, int b){ return a - b;});
            }
        }

        auto operandIt = begin(operands);
        auto operand1 = *operandIt;
        ++operandIt;
        auto operand2 = *operandIt;
        auto operatorIt = begin(operators);
        auto result = (*operatorIt)(operand1, operand2);
        ++operatorIt;
        while (operandIt != end(operands))
        {
            result = operators.front()(result, operands.front());
            ++operandIt;
            ++operatorIt;
        }

        return result;
    }


};
}//namespace basiccalc

#endif //LEETCODESOLUTIONS_BASICCALCULATOR_H
