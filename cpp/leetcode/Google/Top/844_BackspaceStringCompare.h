//https://leetcode.com/problems/backspace-string-compare/
#ifndef ALGORITHMICCHALLENGES_844_BACKSPACESTRINGCOMPARE_H
#define ALGORITHMICCHALLENGES_844_BACKSPACESTRINGCOMPARE_H

#include <string>

using namespace std;

void getNextChar(string::const_reverse_iterator& rIt, const string::const_reverse_iterator& rEnd) {
    int backCnt = 0;
    while (rIt != rEnd && (backCnt > 0 || *rIt == '#')) {
        if (*rIt == '#')
            ++backCnt;
        else
            --backCnt;
        ++rIt;
    }
}

bool backspaceCompare(const string& S, const string& T) {
    auto tIt = rbegin(T), sIt = rbegin(S), tEnd = rend(T), sEnd = rend(S);
    getNextChar(tIt, tEnd);
    getNextChar(sIt, sEnd);
    while (tIt != tEnd && sIt != sEnd) {
        if (*tIt != *sIt)
            return false;
        ++tIt;
        ++sIt;
        getNextChar(tIt, tEnd);
        getNextChar(sIt, sEnd);
    }
    return tIt == tEnd && sIt == sEnd;
}

#endif //ALGORITHMICCHALLENGES_844_BACKSPACESTRINGCOMPARE_H
