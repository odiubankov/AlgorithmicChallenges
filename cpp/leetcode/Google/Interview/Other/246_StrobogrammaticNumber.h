//https://leetcode.com/problems/strobogrammatic-number/
#ifndef ALGORITHMICCHALLENGES_246_STROBOGRAMMATICNUMBER_H
#define ALGORITHMICCHALLENGES_246_STROBOGRAMMATICNUMBER_H
#include <string>
#include <vector>
using namespace std;

bool isStrobogrammatic(const string& num) {
    static const string middle = "018";
    static const string mapping = "001188696";
    if (num.empty())
        return true;
    if (num.length() % 2 != 0 && middle.find(num[num.length() / 2]) == string::npos)
        return false;
    int rightPos = num.length() / 2;
    int leftPos = rightPos - 1;
    if (num.length() % 2 != 0)
        ++rightPos;
    while (leftPos >= 0) {
        auto charPos = mapping.find(num[leftPos]);
        if (charPos == string::npos || num[rightPos] != mapping[charPos + 1])
            return false;
        --leftPos;
        ++rightPos;
    }
    return true;
}

#endif //ALGORITHMICCHALLENGES_246_STROBOGRAMMATICNUMBER_H
