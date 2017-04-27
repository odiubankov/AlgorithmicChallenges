// https://leetcode.com/problems/generate-parentheses/#/description
/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
 [
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */

#ifndef LEETCODESOLUTIONS_GENERATEPARENTHESES_H
#define LEETCODESOLUTIONS_GENERATEPARENTHESES_H

#include <vector>
#include <string>

using namespace std;

namespace generateparentheses
{

class Solution
{
    vector<string> getNext(string currentString, int leftToOpen, int leftToClose)
    {
        vector<string> nextStrings;
        if (leftToOpen > 0)
        {
            nextStrings = getNext(currentString + "(", leftToOpen - 1, leftToClose + 1);
        }

        if (leftToClose > 0)
        {
            auto nextStrings2 = getNext(currentString + ")", leftToOpen, leftToClose - 1);
            std::move(begin(nextStrings2), end(nextStrings2), back_inserter(nextStrings));
        }
        else
        {
            if (leftToOpen == 0)
            {
                return {currentString};
            }
        }

        return nextStrings;
    }

public:
    vector<string> generateParenthesis(int n)
    {
        return getNext("(", n - 1, 1);
    }
};
}

#endif //LEETCODESOLUTIONS_GENERATEPARENTHESES_H
