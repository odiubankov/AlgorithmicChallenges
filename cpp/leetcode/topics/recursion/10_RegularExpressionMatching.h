// https://leetcode.com/problems/regular-expression-matching/
#ifndef ALGORITHMICCHALLENGES_10_REGULAREXPRESSIONMATCHING_H
#define ALGORITHMICCHALLENGES_10_REGULAREXPRESSIONMATCHING_H

#include <string>
#include <cassert>

using namespace std;

bool isMatchImpl(const string& s, int sI, const string& p, int pI) {
    if (sI == s.size() && pI == p.size())
        return true;

    if (sI > s.size() || pI >= p.size())
        return false;

    if (p[pI] == '.') {
        if ((pI + 1) < p.size() && p[pI + 1] == '*') {
            for (int i = sI; i <= s.size(); ++i) {
                if (isMatchImpl(s, i, p, pI + 2))
                    return true;
            }

            return false;
        } else {
            return isMatchImpl(s, sI + 1, p, pI + 1);
        }
    }

    if ((pI + 1) < p.size() && p[pI + 1] == '*') {
        if (isMatchImpl(s, sI, p, pI + 2))
            return true;

        for (int i = sI; i < s.size() && s[i] == p[pI]; ++i) {
            if (isMatchImpl(s, i + 1, p, pI + 2))
                return true;
        }

        return false;
    } else {
        if (sI == s.size())
            return false;

        if (s[sI] != p[pI])
            return false;

        return isMatchImpl(s, sI + 1, p, pI + 1);
    }
}

bool isMatch(string s, string p) {
    return isMatchImpl(s, 0, p, 0);
}

#endif //ALGORITHMICCHALLENGES_10_REGULAREXPRESSIONMATCHING_H
