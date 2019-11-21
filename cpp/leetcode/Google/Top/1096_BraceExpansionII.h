//https://leetcode.com/problems/brace-expansion-ii/
#ifndef ALGORITHMICCHALLENGES_1096_BRACEEXPANSIONII_H
#define ALGORITHMICCHALLENGES_1096_BRACEEXPANSIONII_H

#include <vector>
#include <string>
#include <memory>
#include <stack>
#include <set>
using namespace std;

vector<string> multiply(const vector<vector<string>>::const_iterator& it, const vector<vector<string>>::const_iterator& itE) {
    if (it == itE)
        return { "" };
    vector<string> res;
    for (const auto& str1 : *it) {
        for (const auto& str2 : multiply(it + 1, itE))
            res.push_back(str1 + str2);
    }
    return res;
}

void uniqueSort(vector<string>& strs) {
    set<string> sorted;
    for (const auto& str : strs)
        sorted.insert(str);
    strs.clear();
    copy(begin(sorted), end(sorted), back_inserter(strs));
}

vector<string> braceExpansionII(const string& expression) {
    vector<string> subExprs;
    int openCnt = 0;
    int start = 0;
    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] == '{') {
            ++openCnt;
        } else if (expression[i] == '}') {
            --openCnt;
        } else if (expression[i] == ',' && openCnt == 0) {
            subExprs.push_back(expression.substr(start, i - start));
            start = i + 1;
        }
    }
    if (!subExprs.empty()) {
        subExprs.push_back(expression.substr(start));
        vector<string> res;
        for (const auto& subExpr : subExprs) {
            for (const auto& subRes : braceExpansionII(subExpr))
                res.push_back(subRes);
        }
        uniqueSort(res);
        return res;
    }
    vector<vector<string>> factors;
    start = 0;
    openCnt = 0;
    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] == '{') {
            if (openCnt == 0) {
                if (i > 0 && i > start) {
                     factors.push_back(braceExpansionII(expression.substr(start, i - start)));
                }
                start = i + 1;
            }
            ++openCnt;
        } else if (expression[i] == '}') {
            if (--openCnt == 0) {
                factors.push_back(braceExpansionII(expression.substr(start, i - start)));
                start = i + 1;
            }
        }
    }
    if (start < expression.size())
        factors.push_back({expression.substr(start)});
    if (factors.size() == 1)
        return factors.front();
    auto res = multiply(begin(factors), end(factors));
    uniqueSort(res);
    return res;
}

#endif //ALGORITHMICCHALLENGES_1096_BRACEEXPANSIONII_H
