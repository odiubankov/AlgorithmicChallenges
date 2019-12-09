//https://leetcode.com/problems/remove-invalid-parentheses/
#ifndef ALGORITHMICCHALLENGES_301_REMOVEINVALIDPARENTHESES_H
#define ALGORITHMICCHALLENGES_301_REMOVEINVALIDPARENTHESES_H

#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

string removeChars(const string& s, unordered_set<int> toRemove) {
    string res;
    res.reserve(s.size() - toRemove.size());
    for (int i = 0; i < s.size(); ++i) {
        if (toRemove.find(i) == end(toRemove))
            res += s[i];
    }
    return res;
}

vector<unordered_set<int>> getPosToRemove(vector<int>::const_iterator it, vector<int>::const_iterator itE, int removeCnt) {
    if (removeCnt == 0)
        return {};
    if (removeCnt == distance(it, itE)) {
        unordered_set<int> toRemove{it, itE};
        return {toRemove};
    }
    if (removeCnt == 1) {
        vector<unordered_set<int>> res;
        for (;it != itE; ++it)
            res.push_back({*it});
        return res;
    }
    vector<unordered_set<int>> res1 = getPosToRemove(it + 1, itE, removeCnt);
    vector<unordered_set<int>> res2 = getPosToRemove(it + 1, itE, removeCnt - 1);
    for (auto& toRemove : res2) {
        toRemove.insert(*it);
        res1.push_back(toRemove);
    }
    return res1;
}

bool isValid(const string& s) {
    int openCnt = 0;
    for (auto c : s) {
        if (c == '(') {
            ++openCnt;
        } else if (c == ')') {
            if (--openCnt < 0)
                return false;
        }
    }
    return true;
}

vector<string> fixExpr(const string& s, const vector<int>& toRemove, int removeCnt) {
    auto posToRemove = getPosToRemove(begin(toRemove), end(toRemove), removeCnt);
    unordered_set<string> fixed;
    for (const auto& pToRemove : posToRemove)
        fixed.insert(removeChars(s, pToRemove));
    vector<string> res;
    res.reserve(fixed.size());
    copy(begin(fixed), end(fixed), back_inserter(res));
    return res;
}

vector<string> removeInvalidParentheses(string s) {
    unordered_set<int> toRemove;
    for (int i = 0; i < s.size() && s[i] != '('; ++i) {
        if (s[i] == ')')
            toRemove.insert(i);
    }
    for (int i = s.size() - 1; i >= 0 && s[i] != ')'; --i) {
        if (s[i] == '(')
            toRemove.insert(i);
    }
    s = removeChars(s, toRemove);
    vector<int> opens, closes;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ')') {
            closes.push_back(i);
        } else if (s[i] == '(') {
            opens.push_back(i);
        }
    }

    vector<string> fixed;
    int opensToRemove = 0, closesToRemove = 0;
    if (opens.size() > closes.size()) {
        opensToRemove = opens.size() - closes.size();
    } else {
        closesToRemove = closes.size() - opens.size();
    }
    do {
        vector<string> opensRemoved {s};
        if (opensToRemove > 0)
            opensRemoved = fixExpr(s, opens, opensToRemove);
        for (const auto& withoutOpens : opensRemoved) {
            vector<string> closesRemoved{withoutOpens};
            if (closesToRemove > 0)
                closesRemoved = fixExpr(withoutOpens, closes, closesToRemove);
            copy_if(begin(closesRemoved), end(closesRemoved), back_inserter(fixed), isValid);
        }
        ++opensToRemove;
        ++closesToRemove;
    } while (fixed.empty());
    unordered_set<string> fixedUnique{begin(fixed), end(fixed)};
    fixed.clear();
    copy(begin(fixedUnique), end(fixedUnique), back_inserter(fixed));
    return fixed;
}

#endif //ALGORITHMICCHALLENGES_301_REMOVEINVALIDPARENTHESES_H
