#ifndef ALGORITHMICCHALLENGES_1717_MAXIMUMSCOREFROMREMOVINGSUBSTRINGS_H
#define ALGORITHMICCHALLENGES_1717_MAXIMUMSCOREFROMREMOVINGSUBSTRINGS_H

#include <algorithm>
#include <stack>
#include <string>

int maximumGain(const std::string& s, int x, int y) {
    int maxGain = std::max(x, y);
    int minGain = std::min(x, y);
    char maxSymbol = 'a';
    char minSymbol = 'b';
    if (x < y) {
        maxSymbol = 'b';
        minSymbol = 'a';
    }

    std::stack<char> symbols;
    int gain = 0;
    for (auto c : s) {
        if (c == minSymbol && !symbols.empty() && symbols.top() == maxSymbol) {
            gain += maxGain;
            symbols.pop();
        } else {
            symbols.push(c);
        }
    }

    std::stack<char> symbols2;
    while (!symbols.empty()) {
        if (symbols.top() == minSymbol && !symbols2.empty() && symbols2.top() == maxSymbol) {
            gain += minGain;
            symbols2.pop();
        } else {
            symbols2.push(symbols.top());
        }

        symbols.pop();
    }

    return gain;
}

#endif //ALGORITHMICCHALLENGES_1717_MAXIMUMSCOREFROMREMOVINGSUBSTRINGS_H
