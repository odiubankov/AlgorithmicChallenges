#include "FixInfixExpression.h"
#include <stack>

namespace sedgewick
{

std::string fixInfixExpression(const std::string& expression)
{
    std::stack<char> operators;
    std::stack<std::string> operands;
    std::stack<std::string> finalExpression;

    for (const auto& character : expression)
    {
        switch (character)
        {
            case ' ':
                break;
            case '*':
            case '/':
            case '-':
            case '+':
                operators.push(character);
                break;
            case ')':
            {
                auto operand2 = operands.top();
                operands.pop();
                auto operand1 = operands.top();
                operands.pop();
                std::string newOperand = "( ";
                newOperand += operand1;
                newOperand += " ";
                newOperand += operators.top();
                newOperand += " ";
                newOperand += operand2;
                newOperand += " )";
                operators.pop();
                operands.push(std::move(newOperand));
                break;
            }
            default:
                operands.push(std::string{character});
                break;
        }
    }

    return operands.top();
}

}//namespace sedgewick
