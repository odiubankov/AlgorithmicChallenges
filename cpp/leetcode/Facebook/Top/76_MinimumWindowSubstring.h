//https://leetcode.com/problems/minimum-window-substring/
#ifndef ALGORITHMICCHALLENGES_76_MINIMUMWINDOWSUBSTRING_H
#define ALGORITHMICCHALLENGES_76_MINIMUMWINDOWSUBSTRING_H

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

using ChCntT = unordered_map<char, int>;
using StrItT = string::const_iterator;

ChCntT calcChCnt(const string& str) {
    ChCntT chCnt;
    for (char c : str)
        ++chCnt[c];
    return chCnt;
}

StrItT getWindowEnd(StrItT strIt, StrItT strEnd, ChCntT& chCnt, size_t numToFind) {
    for (; strIt != strEnd; ++strIt) {
        auto chIt = chCnt.find(*strIt);
        if (chIt != end(chCnt)) {
            if (--(chIt->second) >= 0) {
                if (--numToFind == 0)
                    return strIt;
            }
        }
    }
    return strEnd;
}

StrItT getWindowBegin(StrItT it, ChCntT& chCnt) {
    for (;;++it) {
        auto chIt = chCnt.find(*it);
        if (chIt != end(chCnt)) {
            if (chIt->second >= 0)
                return it;
            ++(chIt->second);
        }
    }
}

string minWindow(const string& str1, const string& str2) {
    if (str2.empty())
        return "";
    auto chCnt = calcChCnt(str2);
    auto windowEnd = getWindowEnd(begin(str1), end(str1), chCnt, str2.length());
    if (windowEnd == end(str1))
        return "";
    auto windowBegin = getWindowBegin(begin(str1), chCnt);
    auto minWindowBegin = windowBegin;
    auto minWindowEnd = windowEnd;
    for(;;) {
        ++chCnt[*windowBegin];
        windowEnd = getWindowEnd(windowEnd + 1, end(str1), chCnt, 1);
        if (windowEnd == end(str1))
            break;
        windowBegin = getWindowBegin(windowBegin + 1, chCnt);
        if (distance(windowBegin, windowEnd) < distance(minWindowBegin, minWindowEnd)) {
            minWindowBegin = windowBegin;
            minWindowEnd = windowEnd;
        }
    }
    return string(minWindowBegin, minWindowEnd + 1);
}

#endif //ALGORITHMICCHALLENGES_76_MINIMUMWINDOWSUBSTRING_H
