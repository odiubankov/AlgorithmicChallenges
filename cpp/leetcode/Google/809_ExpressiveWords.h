//https://leetcode.com/problems/expressive-words/
#ifndef ALGORITHMICCHALLENGES_809_EXPRESSIVEWORDS_H
#define ALGORITHMICCHALLENGES_809_EXPRESSIVEWORDS_H

#include <string>
#include <vector>

using namespace std;

int expressiveWords(const string& S, const vector<string>& words) {
    return count_if(begin(words), end(words),
        [&S](const auto& word) {
        auto sIt = begin(S);
        auto wordIt = begin(word);
        while (sIt != end(S)) {
            auto groupChar = *sIt;
            size_t cnt = 1;
            ++sIt;
            while (sIt != end(S) && *sIt == groupChar) {
                ++cnt;
                ++sIt;
            }
            if (wordIt == end(word) || *wordIt != groupChar)
                return false;
            size_t wordCnt = 1;
            ++wordIt;
            while (wordIt != end(word) && *wordIt == groupChar) {
                ++wordCnt;
                ++wordIt;
            }
            if (wordCnt > cnt || (wordCnt < cnt && cnt < 3))
                return false;
        }
        return true;
    });
}

#endif //ALGORITHMICCHALLENGES_809_EXPRESSIVEWORDS_H
