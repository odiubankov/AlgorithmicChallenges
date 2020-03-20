//https://leetcode.com/problems/alien-dictionary/
#ifndef ALGORITHMICCHALLENGES_269_ALIENDICTIONARY_H
#define ALGORITHMICCHALLENGES_269_ALIENDICTIONARY_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

using CharDependencies = unordered_map<char, unordered_set<char>>;

string alienOrder(const vector<string>& words) {
    if (words.empty())
        return {};

    CharDependencies charsAfter;
    for (const auto& word : words) {
        for (auto c : word) {
            charsAfter[c];
        }
    }
    auto charsBefore = charsAfter;

    for (auto prevWordIt = begin(words), wordIt = begin(words) + 1; wordIt != end(words); ++wordIt, ++prevWordIt) {
        auto charItPrev = begin(*prevWordIt);
        auto charItCurrent = begin(*wordIt);
        while (charItPrev != end(*(prevWordIt))) {
            if (charItCurrent == end(*wordIt)) {
                return "";
            }
            if (*charItCurrent == *charItPrev) {
                ++charItPrev;
                ++charItCurrent;
            } else {
                charsAfter[*charItPrev].insert(*charItCurrent);
                charsBefore[*charItCurrent].insert(*charItPrev);
                break;
            }
        }
    }

    queue<char> charsQueue;
    for (const auto& c : charsBefore) {
        if (c.second.empty()) {
            charsQueue.push(c.first);
        }
    }

    string alphabet;
    alphabet.reserve(charsAfter.size());
    while (!charsQueue.empty()) {
        auto c = charsQueue.front();
        alphabet.push_back(c);
        charsQueue.pop();
        for (auto after : charsAfter[c]) {
            charsBefore[after].erase(c);
            if (charsBefore[after].empty()) {
                charsQueue.push(after);
            }
        }
    }

    if (alphabet.size() != charsAfter.size())
        return "";

    return alphabet;
}

#endif //ALGORITHMICCHALLENGES_269_ALIENDICTIONARY_H
