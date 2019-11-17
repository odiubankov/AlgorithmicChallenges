//https://leetcode.com/problems/minimum-window-subsequence/
#ifndef ALGORITHMICCHALLENGES_727_MINIMUMWINDOWSUBSEQUENCE_H
#define ALGORITHMICCHALLENGES_727_MINIMUMWINDOWSUBSEQUENCE_H

#include <string>
#include <unordered_map>
#include <limits>
#include <vector>
using namespace std;

string minWindow(const string& S, const string& T) {
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

#endif //ALGORITHMICCHALLENGES_727_MINIMUMWINDOWSUBSEQUENCE_H
