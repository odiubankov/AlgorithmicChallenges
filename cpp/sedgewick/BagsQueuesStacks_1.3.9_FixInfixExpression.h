#ifndef ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_9_FIXINFIXEXPRESSION_H
#define ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_9_FIXINFIXEXPRESSION_H
#include <string>
#include <stack>

namespace sedgewick
{

bool isNextCharacterNonNumber(const std::stack<char, std::string>& expr)
{
    return expr.empty() || (expr.top() < '0' || expr.top() > '9');
}

std::string fixInfix(const std::string& str)
{
    std::stack<char, std::string> wrongInfixExpr{str};
    std::stack<char, std::string> correctInfixExpr;
    int operands = 0;
    int nums = 0;
    while (!wrongInfixExpr.empty())
    {
        auto c = wrongInfixExpr.top();
        wrongInfixExpr.pop();
        if (c == ')')
        {
            correctInfixExpr.push(c);
        }
        else if (c >= '0' && c <= '9')
        {
            correctInfixExpr.push(c);
            if (isNextCharacterNonNumber(wrongInfixExpr))
                ++nums;
            if (nums == 2)
            {
                for (int i = 0; i < operands; ++i)
                    correctInfixExpr.push('(');
                nums = 0;
                operands = 0;
            }
        }
        else
        {
            ++operands;
            correctInfixExpr.push(c);
        }
    }

    std::string result;
    while (!correctInfixExpr.empty())
    {
        result.push_back(correctInfixExpr.top());
        correctInfixExpr.pop();
    }

    return result;
}

}

#endif //ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_9_FIXINFIXEXPRESSION_H
