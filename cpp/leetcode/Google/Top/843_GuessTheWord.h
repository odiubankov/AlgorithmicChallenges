//https://leetcode.com/problems/guess-the-word/
#ifndef ALGORITHMICCHALLENGES_843_GUESSTHEWORD_H
#define ALGORITHMICCHALLENGES_843_GUESSTHEWORD_H

#include <vector>
#include <string>
#include <array>
#include <unordered_set>
#include <limits>
#include <iostream>

using namespace std;


// This is the Master's API interface.
// You should not implement it, or speculate about its implementation
class Master {
  public:
    int guess(string word);
    size_t callCnt_ = 0;
};

class Solution {
public:
    struct WordInfo{
        array<unordered_set<size_t>, 6> sameLetters_;
    };

    void findSecretWord(const vector<string>& wordlist, Master& master) {
        vector<WordInfo> words;
        words.resize(wordlist.size());
        for (size_t i = 0; i < wordlist.size(); ++i) {
            for (size_t j = i + 1; j < wordlist.size(); ++j) {
                size_t sameCnt = 0;
                for (size_t k = 0; k < 6; ++k) {
                    if (wordlist[i][k] == wordlist[j][k])
                        ++sameCnt;
                }
                words[i].sameLetters_[sameCnt].insert(j);
                words[j].sameLetters_[sameCnt].insert(i);
            }
        }
        unordered_set<size_t> indexes;
        unordered_set<size_t> incorrect;
        indexes.reserve(wordlist.size());
        for (size_t i = 0; i < wordlist.size(); ++i)
            indexes.insert(i);

        size_t sameCnt = 0;
        do {
            for (size_t i : indexes) {
                for (size_t j = 0; j < 6; ++j) {
                    for (auto it = begin(words[i].sameLetters_[j]); it != end(words[i].sameLetters_[j]);) {
                        if (incorrect.find(*it) != end(incorrect)) {
                            it = words[i].sameLetters_[j].erase(it);
                        } else {
                            ++it;
                        }
                    }
                }
            }
            size_t minCnt = numeric_limits<size_t>::max();
            size_t minMaxGroup = indexes.size();
            for (size_t i : indexes) {
                size_t maxGroup = 0;
                for (size_t j = 0; j < 6; ++j) {
                    if (words[i].sameLetters_[j].size() > maxGroup)
                        maxGroup = words[i].sameLetters_[j].size();
                }
                if (maxGroup < minCnt) {
                    minCnt = maxGroup;
                    minMaxGroup = i;
                }
            }
            sameCnt = master.guess(wordlist[minMaxGroup]);
            incorrect.insert(minMaxGroup);
            for (size_t i = 0; i < 6 ; ++i) {
                if (i != sameCnt) {
                    for (size_t j : words[minMaxGroup].sameLetters_[i])
                        incorrect.insert(j);
                }
            }
            indexes = words[minMaxGroup].sameLetters_[sameCnt];
        } while(sameCnt != 6);
    }
};

#endif //ALGORITHMICCHALLENGES_843_GUESSTHEWORD_H
