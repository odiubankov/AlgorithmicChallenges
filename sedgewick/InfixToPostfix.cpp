#include "InfixToPostfix.h"
#include <stack>

namespace sedgewick
{

std::string shuntingYard(const std::string &expr)
{
    std::stack<char> tokens;
    std::string output;

    for (const char &character : expr) {
        if (isdigit(character)) {
            output.append(1, character);
        }
        else if (
            character == '+' ||
                character == '-' ||
                character == '/' ||
                character == '*') {
            if (character == '+' ||
                character == '-') {
                while (!tokens.empty() && (tokens.top() == '/' || tokens.top() == '*')) {
                    output.append(1, tokens.top());
                    tokens.pop();
                }
            }

            tokens.push(character);
        }
        else if (character == '(') {
            tokens.push(character);
        }
        else if (character == ')') {
            while (!tokens.empty() && tokens.top() != '(') {
                output.append(1, tokens.top());
                tokens.pop();
            }

            if (!tokens.empty() && tokens.top() == '(') {
                tokens.pop();
            }
        }
    }

    while (!tokens.empty()) {
        output.append(1, tokens.top());
        tokens.pop();
    }

    return output;
}

}//namespace sedgewick
