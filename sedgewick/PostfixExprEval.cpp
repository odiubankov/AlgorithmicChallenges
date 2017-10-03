#include "PostfixExprEval.h"
#include <stack>

namespace sedgewick
{

int postfixExprEval(const std::string &str)
{
    std::stack<int> operands;
    for (const auto &character : str) {
        if (isdigit(character)) {
            operands.push(character - '0');
        }
        else {
            auto operand2 = operands.top();
            operands.pop();
            int result;
            switch (character) {
                case '+':result = operands.top() + operand2;
                    break;
                case '-':result = operands.top() - operand2;
                    break;
                case '*':result = operands.top() * operand2;
                    break;
                default:result = operands.top() / operand2;
                    break;
            }

            operands.pop();
            operands.push(result);
        }
    }

    return operands.top();
}

}//namespace sedgewick