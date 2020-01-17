//https://leetcode.com/problems/word-ladder/
#ifndef ALGORITHMICCHALLENGES_127_WORDLADDER_H
#define ALGORITHMICCHALLENGES_127_WORDLADDER_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
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

using WordTransformationsT = unordered_map<string, vector<string>>;

void addWordTransformations(const string& word, WordTransformationsT& wordToTransformations, WordTransformationsT& transformationToWords) {
    auto wordTransformation = word;
    for (size_t char_i = 0; char_i != word.length(); ++char_i) {
        auto replacedChar = wordTransformation[char_i];
        wordTransformation[char_i] = '*';
        transformationToWords[wordTransformation].push_back(word);
        wordToTransformations[word].push_back(wordTransformation);
        wordTransformation[char_i] = replacedChar;
    }
}

int ladderLengthDFS(const string& beginWord, const string& endWord, const WordsT& wordList) {
    unordered_map<string, vector<string>> wordToTransformations, transformationToWords;
    addWordTransformations(beginWord, wordToTransformations, transformationToWords);
    for (const auto& word : wordList)
        addWordTransformations(word, wordToTransformations, transformationToWords);

    unordered_set<string> visitedWords;
    queue<pair<string, int>> ladder;
    ladder.emplace(beginWord, 1);
    while (!ladder.empty()) {
        auto nextWord = ladder.front();
        if (nextWord.first == endWord)
            return nextWord.second;
        ladder.pop();
        visitedWords.insert(nextWord.first);
        for (const auto& wordTransformation : wordToTransformations[nextWord.first]) {
            for (const auto& word : transformationToWords[wordTransformation]) {
                if (visitedWords.find(word) == end(visitedWords)) {
                    ladder.emplace(word, nextWord.second + 1);
                }
            }
        }
    }
    return 0;
}

#endif //ALGORITHMICCHALLENGES_127_WORDLADDER_H
