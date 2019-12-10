//https://leetcode.com/problems/word-ladder/
#ifndef ALGORITHMICCHALLENGES_127_WORDLADDER_H
#define ALGORITHMICCHALLENGES_127_WORDLADDER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using WordsT = vector<string>;

int ladderLength(string beginWord, const string& endWord, WordsT& wordList) {
    auto endWordIt = find(begin(wordList), end(wordList), endWord);
    if (endWordIt == end(wordList))
        return 0;
    size_t endWordIndex = distance(begin(wordList), endWordIt);
    wordList.push_back(move(beginWord));
    vector<vector<size_t>> oneAwayWords_(wordList.size());
    const size_t wordLength = endWord.length();
    for (size_t w1 = 0; w1 < wordList.size(); ++w1) {
        for (size_t w2 = w1 + 1; w2 < wordList.size(); ++w2) {
            bool diffFound = false;
            bool oneAway = true;
            for (size_t c = 0; c < wordLength; ++c) {
                if (wordList[w1][c] != wordList[w2][c]) {
                    if (diffFound) {
                        oneAway = false;
                        break;
                    } else {
                        diffFound = true;
                    }
                }
            }
            if (oneAway) {
                oneAwayWords_[w1].push_back(w2);
                oneAwayWords_[w2].push_back(w1);
            }
        }
    }
    queue<pair<size_t, int>> toVisit;
    toVisit.emplace(oneAwayWords_.size() - 1, 1);
    vector<char> visited(oneAwayWords_.size(), 0);
    visited.back() = 1;
    while (!toVisit.empty()) {
        auto nextWord = toVisit.front();
        if (nextWord.first == endWordIndex)
            return nextWord.second;
        toVisit.pop();
        for (auto oneAway : oneAwayWords_[nextWord.first]) {
            if (visited[oneAway] == 0) {
                toVisit.emplace(oneAway, nextWord.second + 1);
                visited[oneAway] = 1;
            }
        }
    }
    return 0;
}

#endif //ALGORITHMICCHALLENGES_127_WORDLADDER_H
