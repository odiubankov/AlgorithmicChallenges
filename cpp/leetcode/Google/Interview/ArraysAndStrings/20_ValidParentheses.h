//https://leetcode.com/problems/valid-parentheses/
#ifndef ALGORITHMICCHALLENGES_20_VALIDPARENTHESES_H
#define ALGORITHMICCHALLENGES_20_VALIDPARENTHESES_H

#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

bool isOpen(char c) {
    return c == '{' || c == '(' || c == '[';
}

char getOpen(char close) {
    static const unordered_map<char, char> opens{ {'}', '{'}, {')', '('}, { ']', '[' } };
    return opens.at(close);
}

bool isValid(const string& s) {
    stack<char> openings;
    for (auto c : s) {
        if (isOpen(c)) {
            openings.push(c);
        } else { // close
            if (openings.empty() || openings.top() != getOpen(c))
                return false;
            openings.pop();
        }
    }
    return openings.empty();
}

#endif //ALGORITHMICCHALLENGES_20_VALIDPARENTHESES_H
