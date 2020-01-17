//https://leetcode.com/problems/word-break/
#ifndef ALGORITHMICCHALLENGES_139_WORDBREAK_H
#define ALGORITHMICCHALLENGES_139_WORDBREAK_H

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;
using BreakResT = unordered_map<string, bool>;
using DictT = unordered_set<string>;

bool wordBreakImpl(const string& s, const DictT& dict, BreakResT& res) {
    auto resIt = res.find(s);
    if (resIt != end(res))
        return resIt->second;
    auto breakRes = dict.find(s) != end(dict);
    if (!breakRes) {
        for (size_t i = 1; i < s.length(); ++i) {
            if (wordBreakImpl(s.substr(0, i), dict, res) && wordBreakImpl(s.substr(i), dict, res)) {
                breakRes = true;
                break;
            }
        }
    }
    res[s] = breakRes;
    return breakRes;
}

bool wordBreak(const string& s, const vector<string>& wordDict) {
    DictT words;
    BreakResT breakRes;
    for (auto& word : wordDict)
        words.insert(word);
    return wordBreakImpl(s, words, breakRes);
}

bool wordBreakDFS(const string& s, const vector<string>& wordDict) {
    unordered_map<size_t, vector<size_t>> substrPos;
    for (const auto& word : wordDict) {
        size_t pos = s.find(word);
        while (pos != string::npos) {
            substrPos[pos].push_back(pos + word.size());
            pos = s.find(word, pos+1);
        }
    }
    if (substrPos.find(0) == end(substrPos))
        return false;
    unordered_set<size_t> beginsInQueue;
    queue<size_t> begins;
    begins.push(0);
    while (!begins.empty()) {
        auto nextBegin = begins.front();
        begins.pop();
        for (auto nextEnd : substrPos[nextBegin]) {
            if (beginsInQueue.find(nextEnd) == end(beginsInQueue)) {
                if (nextEnd == s.size())
                    return true;
                begins.push(nextEnd);
                beginsInQueue.insert(nextEnd);
            }
        }
    }
    return false;
}

#endif //ALGORITHMICCHALLENGES_139_WORDBREAK_H
