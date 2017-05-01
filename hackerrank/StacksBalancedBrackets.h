#ifndef LEETCODESOLUTIONS_STACKSBALANCEDBRACKETS_H
#define LEETCODESOLUTIONS_STACKSBALANCEDBRACKETS_H

#include <stack>
#include <string>

using namespace std;

namespace hackerrank
{
    bool is_balanced(string expression)
    {
        stack<char> openedBrackets;
        for (const auto& character : expression)
        {
            switch(character)
            {
                case '(':
                case '[':
                case '{':
                    openedBrackets.push(character);
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
            }
        }

        return openedBrackets.empty();
    }
}

#endif //LEETCODESOLUTIONS_STACKSBALANCEDBRACKETS_H
