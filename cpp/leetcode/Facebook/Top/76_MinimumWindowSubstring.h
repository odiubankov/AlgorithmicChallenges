//https://leetcode.com/problems/minimum-window-substring/
#ifndef ALGORITHMICCHALLENGES_76_MINIMUMWINDOWSUBSTRING_H
#define ALGORITHMICCHALLENGES_76_MINIMUMWINDOWSUBSTRING_H

#include <string>
#include <unordered_map>
using namespace std;

string minWindow(const string& str1, const string& str2) {
    if (str2.empty())
        return "";
    unordered_map<char, int> chCnt;
    for (char c : str2)
        ++chCnt[c];
    auto inStr2 = [&chCnt](auto c){ return chCnt.find(c) != end(chCnt); };
    auto chIt = find_if(begin(str1), end(str1), inStr2);
    if (chIt == end(str1))
        return "";
    auto toFind = str2.size() - 1;
    --chCnt[*chIt];
    auto sB = chIt;
    ++chIt;
    while (toFind != 0 && chIt != end(str1)) {
        chIt = find_if(chIt, end(str1), inStr2);
        if (chIt == end(str1))
            return "";
        if (--chCnt[*chIt] >= 0)
            --toFind;
        ++chIt;
    }
    if (toFind != 0)
        return "";
    auto resSize = distance(sB, chIt);
    auto resB = sB;
    do {
        bool needFind = false;
        char c;
        if (++chCnt[*sB] == 1) {
            needFind = true;
            c = *sB;
        }
        ++sB;
        for (;sB != end(str1); ++sB) {
            auto chCntIt = chCnt.find(*sB);
            if (chCntIt != end(chCnt)){
                if (chCntIt->second >= 0)
                    break;
                ++chCntIt->second;
            }
        }

        while (chIt != end(str1) && needFind) {
            chIt = find_if(chIt, end(str1), inStr2);
            if (chIt == end(str1))
                break;
            --chCnt[*chIt];
            if (*chIt == c)
                needFind = false;
            ++chIt;
        }
        if (needFind)
            break;
        auto newSize = distance(sB, chIt);
        if (newSize < resSize) {
            resSize = newSize;
            resB = sB;
        }
    } while (resSize > str2.size());
    return string{resB, resB + resSize};
}

#endif //ALGORITHMICCHALLENGES_76_MINIMUMWINDOWSUBSTRING_H
