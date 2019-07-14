#ifndef ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_10_INFIXTOPOSTFIX_H
#define ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_10_INFIXTOPOSTFIX_H

#include <string>
#include <stack>
#include <vector>

namespace sedgewick
{

std::string infixToPostfix(const std::string& infixExpr)
{
    std::stack<char> operators;
    std::string postfixExpr;
    std::vector<char> number;
    for (auto character : infixExpr)
    {
        switch (character)
        {
            case '+':
            case '-':
            case '*':
            case '/':
                std::copy(begin(number), end(number), std::back_inserter(postfixExpr));
                number.clear();
                operators.push(character);
                break;
            case '(':
                break;
            case ')':
                if (!number.empty())
                {
                    postfixExpr.push_back(' ');
                    std::copy(begin(number), end(number), std::back_inserter(postfixExpr));
                    number.clear();
                }
                postfixExpr.push_back(operators.top());
                operators.pop();
                break;
            default:/*digit*/
                number.push_back(character);
                break;
        }
    }
    return postfixExpr;
}

}

#endif //ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_10_INFIXTOPOSTFIX_H
