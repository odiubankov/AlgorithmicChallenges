#ifndef ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_11_EVALUATEPOSTFIX_H
#define ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_11_EVALUATEPOSTFIX_H

#include <string>
#include <stack>
#include <cassert>

namespace sedgewick
{

bool isOperator(char character)
{
    switch(character)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }

    return false;
}

void addOperand(std::stack<int>& operands, std::string& number) {
    operands.push(std::stoi(number));
    number.clear();
}

int evaluatePostfix(const std::string& expr) {
    std::stack<int> operands;
    std::string number;
    for (auto character : expr) {
        if (character == ' ')
            addOperand(operands, number);
        else if (isOperator(character)) {
            if (!number.empty())
                addOperand(operands, number);
            auto operand2 = operands.top();
            operands.pop();
            auto operand1 = operands.top();
            operands.pop();
            int result = 0;
            switch(character) {
                case '/': {
                    result = operand1 / operand2;
                    break;
                }
                case '*': {
                    result = operand1 * operand2;
                    break;
                }
                case '+': {
                    result = operand1 + operand2;
                    break;
                }
                case '-': {
                    result = operand1 - operand2;
                    break;
                }
            }
            operands.push(result);
        }
        else { //digit
            number.push_back(character);
        }
    }

    assert(operands.size() == 1);
    return operands.top();
}

}
#endif //ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_11_EVALUATEPOSTFIX_H
