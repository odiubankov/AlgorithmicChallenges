//https://leetcode.com/problems/swap-adjacent-in-lr-string/
#ifndef ALGORITHMICCHALLENGES_777_SWAPADJACENTINLRSTRING_H
#define ALGORITHMICCHALLENGES_777_SWAPADJACENTINLRSTRING_H

#include <string>
#include <unordered_map>
using namespace std;

bool canTransform(string& startStr, const string& endStr) {
    unordered_map<char, int> charsCnt;
    for (auto c : startStr) {
        ++charsCnt[c];
    }
    for (auto c : endStr) {
        if (--charsCnt[c] < 0)
            return false;
    }
    for (size_t i = 0; i < startStr.length(); ++i) {
        if (startStr[i] != endStr[i]) {
            if (startStr[i] == 'X' && endStr[i] == 'L') {
                bool lFound = false;
                for (int j = i + 1; j < startStr.length(); ++j) {
                    if (startStr[i] == 'R')
                        return false;
                    if (startStr[j] == 'L') {
                        lFound = true;
                        startStr[j] = 'X';
                        break;
                    }
                }
                if (!lFound)
                    return false;
            } else if (startStr[i] == 'L' && endStr[i] == 'X') {
                return false;
            } else if (startStr[i] == 'R' && endStr[i] == 'L') {
                return false;
            } else if (startStr[i] == 'L' && endStr[i] == 'R') {
                return false;
            } else if (startStr[i] == 'X' && endStr[i] == 'R') {
                return false;
            } else if (startStr[i] == 'R' && endStr[i] == 'X') {
                bool xFound = false;
                for (int j = i + 1; j < startStr.length(); ++j) {
                    if (startStr[j] == 'L')
                        return false;
                    if (startStr[j] == 'X') {
                        xFound = true;
                        startStr[j] = 'R';
                        break;
                    }
                }
                if (!xFound)
                    return false;
            }
        }
    }
    return true;
}

#endif //ALGORITHMICCHALLENGES_777_SWAPADJACENTINLRSTRING_H
