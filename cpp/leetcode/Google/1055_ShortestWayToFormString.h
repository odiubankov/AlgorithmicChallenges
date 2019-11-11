//https://leetcode.com/problems/shortest-way-to-form-string/
#ifndef ALGORITHMICCHALLENGES_1055_SHORTESTWAYTOFORMSTRING_H
#define ALGORITHMICCHALLENGES_1055_SHORTESTWAYTOFORMSTRING_H

#include <string>
#include <vector>
using namespace std;

//O(ts)
int shortestWay(const string& source, const string& target) {
    if (target.empty())
        return 0;
    int parts = 1;
    size_t pos = 0;
    for (char c : target) {
        size_t newPos = source.find(c, pos);
        if (newPos == string::npos) {
            newPos = source.find(c, 0);
            if (newPos == string::npos)
                return -1;
            ++parts;
        }
        pos = newPos + 1;
    }
    return parts;
}

// O(s*log s + t*log s) = O((s + t)*log s)
int shortestWayLog(const string& source, const string& target) {
    if (target.empty())
        return 0;
    vector<pair<char, size_t>> charPositions;
    charPositions.reserve(source.size());
    for (size_t i = 0; i < source.size(); ++i)
        charPositions.emplace_back(source[i], i);
    sort(begin(charPositions), end(charPositions));
    int parts = 1;
    size_t pos = 0;
    for (char c : target) {
        auto chIt = lower_bound(begin(charPositions), end(charPositions), make_pair(c, pos));
        if (chIt == end(charPositions) || chIt->first != c) {
            chIt = lower_bound(begin(charPositions), end(charPositions), pair<char, size_t>{c, 0});
            if (chIt == end(charPositions) || chIt->first != c)
                return -1;
            ++parts;
        }
        pos = chIt->second + 1;
    }
    return parts;
}

#endif //ALGORITHMICCHALLENGES_1055_SHORTESTWAYTOFORMSTRING_H
