//https://leetcode.com/problems/remove-invalid-parentheses/
#ifndef ALGORITHMICCHALLENGES_301_REMOVEINVALIDPARENTHESES_H
#define ALGORITHMICCHALLENGES_301_REMOVEINVALIDPARENTHESES_H

#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

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
    return openCnt == 0;
}

vector<string> removeInvalidParentheses_dfs(string s) {
    unordered_set<string> fixed;
    unordered_set<string> inQueue;
    std::queue<string> q;
    q.push(s);
    inQueue.insert(s);
    while (!q.empty()) {
        auto nextS = q.front();
        q.pop();
        if (isValid(nextS)) {
            if (fixed.empty() || fixed.begin()->length() == nextS.length()) {
                fixed.emplace(move(nextS));
            }
        }
        else {
            for (size_t i = 0; i < nextS.length(); ++i) {
                if (nextS[i] == '(' || nextS[i] == ')') {
                    auto patchedS = nextS.substr(0, i);
                    patchedS.append(nextS.substr(i + 1));
                    if (inQueue.find(patchedS) == end(inQueue)) {
                        q.push(patchedS);
                        inQueue.insert(patchedS);
                    }
                }
            }
        }
    }

    return vector<string>(begin(fixed), end(fixed));
}

#endif //ALGORITHMICCHALLENGES_301_REMOVEINVALIDPARENTHESES_H
