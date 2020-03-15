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

    static const int LettersCnt = 6;

    using SameLettersCntWordsT = array<unordered_set<size_t>, LettersCnt>;
    vector<SameLettersCntWordsT> cntSameLetters(const vector<string>& wordList) {
        vector<SameLettersCntWordsT> sameLettersWords(wordList.size());
        for (size_t i = 0; i < wordList.size(); ++i) {
            for (size_t j = i + 1; j < wordList.size(); ++j) {
                size_t sameCnt = 0;
                for (size_t k = 0; k < LettersCnt; ++k) {
                    if (wordList[i][k] == wordList[j][k])
                        ++sameCnt;
                }
                sameLettersWords[i][sameCnt].insert(j);
                sameLettersWords[j][sameCnt].insert(i);
            }
        }
        return sameLettersWords;
    }

    void fillAllIndexes(vector<size_t>& indexesToCheck, size_t cnt) {
        indexesToCheck.reserve(cnt);
        for (size_t i = 0; i < cnt; ++i)
            indexesToCheck.push_back(i);
    }

    void findSecretWord(const vector<string>& wordList, Master& master) {
        auto sameLettersWords = cntSameLetters(wordList);

        vector<size_t> indexesToCheck;
        fillAllIndexes(indexesToCheck, wordList.size());

        unordered_set<size_t> incorrectIndexes;
        for(;;) {
            size_t minMaxSameLettersCnt = numeric_limits<size_t>::max();
            size_t indexToTry = numeric_limits<size_t>::max();
            for (size_t i : indexesToCheck) {
                size_t maxGroupItemsCnt = 0;
                for (size_t j = 0; j < LettersCnt; ++j) {
                    const auto& sameCntIndexes = sameLettersWords[i][j];
                    auto sameCntIndexesCnt = std::count_if(begin(sameCntIndexes), end(sameCntIndexes),
                        [&incorrectIndexes](auto index){
                        return incorrectIndexes.find(index) == end(incorrectIndexes); });
                    maxGroupItemsCnt = std::max<size_t>(maxGroupItemsCnt, sameCntIndexesCnt);
                }

                if (maxGroupItemsCnt < minMaxSameLettersCnt) {
                    minMaxSameLettersCnt = maxGroupItemsCnt;
                    indexToTry = i;
                }
            }

            auto sameCnt = master.guess(wordList[indexToTry]);
            if (sameCnt == LettersCnt)
                return;

            incorrectIndexes.insert(indexToTry);
            for (size_t i = 0; i < LettersCnt ; ++i) {
                if (i != sameCnt) {
                    for (size_t j : sameLettersWords[indexToTry][i])
                        incorrectIndexes.insert(j);
                }
            }

            indexesToCheck.clear();
            const auto& sameCntIndexes = sameLettersWords[indexToTry][sameCnt];
            std::copy_if(begin(sameCntIndexes), end(sameCntIndexes), std::back_inserter(indexesToCheck),
                [&incorrectIndexes](auto i) { return incorrectIndexes.find(i) == end(incorrectIndexes); });
        }
    }
};

#endif //ALGORITHMICCHALLENGES_843_GUESSTHEWORD_H
