//https://leetcode.com/problems/word-break/
#ifndef ALGORITHMICCHALLENGES_139_WORDBREAK_H
#define ALGORITHMICCHALLENGES_139_WORDBREAK_H

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using BreakResT = unordered_map<string, bool>;
using DictT = unordered_set<string>;

bool wordBreakImpl(const string& s, const DictT& dict, BreakResT& res) {
    auto resIt = res.find(s);
    if (resIt != end(res))
        return resIt->second;
    auto breakRes = dict.find(s) != end(dict);
    if (!breakRes && s.length() > 1) {
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

#endif //ALGORITHMICCHALLENGES_139_WORDBREAK_H
