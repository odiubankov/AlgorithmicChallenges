//https://leetcode.com/problems/minimum-window-subsequence/
#ifndef ALGORITHMICCHALLENGES_727_MINIMUMWINDOWSUBSEQUENCE_H
#define ALGORITHMICCHALLENGES_727_MINIMUMWINDOWSUBSEQUENCE_H

#include <string>
#include <unordered_map>
#include <limits>
#include <vector>
using namespace std;

string minWindow2(const string& S, const string& T) {
    size_t minLength = numeric_limits<size_t>::max();
    size_t minLengthStart = numeric_limits<size_t>::max();
    unordered_map<char, vector<pair<size_t, size_t>>> waitingCharacters;
    waitingCharacters[T.front()] = {make_pair<size_t, size_t>(0, 0)};
    for (size_t i = 0; i < S.length(); ++i) {
        char c = S[i];
        auto wCh = waitingCharacters.find(c);
        if (wCh != end(waitingCharacters)) {
            vector<pair<size_t, size_t>> posToUpdate = std::move(wCh->second);
            waitingCharacters.erase(wCh);
            for (auto& pos : posToUpdate) {
                if (pos.first == 0) {
                    pos.second = i;
                    waitingCharacters[T.front()].push_back(make_pair<size_t, size_t>(0, 0));
                }
                ++pos.first;
                if (pos.first == T.length()) {
                    size_t length = i - pos.second + 1;
                    if (length < minLength) {
                        minLength = length;
                        minLengthStart = pos.second;
                    }
                } else {
                    waitingCharacters[T[pos.first]].push_back(pos);
                }
            }
        }
    }
    if (minLengthStart == numeric_limits<size_t>::max())
        return "";
    return S.substr(minLengthStart, minLength);
}

string minWindowSlidingWindow(const string& S, const string& T) {
    if (T.empty())
        return "";
    auto minSubstrBegin = end(S);
    auto minSubstrEnd = end(S);
    auto substrBegin = end(S);
    auto substrEnd = end(S);
    auto sIt = begin(S);
    auto tIt = begin(T);
    while (sIt != end(S)) {
        if (*sIt == *tIt) {
            if (substrBegin == end(S)) {
                substrBegin = sIt;
            }
            ++sIt;
            ++tIt;
            if (tIt == end(T)) {
                substrEnd = sIt;
                do {
                    --sIt;
                    --tIt;
                    while (*sIt != *tIt)
                        --sIt;
                } while (tIt != begin(T));
                substrBegin = sIt;
                if (minSubstrBegin == end(S) ||
                    distance(minSubstrBegin, minSubstrEnd) > distance(substrBegin, substrEnd)) {
                    minSubstrBegin = substrBegin;
                    minSubstrEnd = substrEnd;
                }
                substrBegin = end(S);
                tIt = begin(T);
                ++sIt;
            }
        } else {
            ++sIt;
        }
    }
    if (minSubstrBegin == end(S))
        return "";
    return string(minSubstrBegin, minSubstrEnd);
}

#endif //ALGORITHMICCHALLENGES_727_MINIMUMWINDOWSUBSEQUENCE_H
