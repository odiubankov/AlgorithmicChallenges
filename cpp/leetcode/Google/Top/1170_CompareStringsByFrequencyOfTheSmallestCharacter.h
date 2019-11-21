//https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
#ifndef ALGORITHMICCHALLENGES_1170_COMPARESTRINGSBYFREQUENCYOFTHESMALLESTCHARACTER_H
#define ALGORITHMICCHALLENGES_1170_COMPARESTRINGSBYFREQUENCYOFTHESMALLESTCHARACTER_H

#include <vector>
#include <string>
#include <limits>

using namespace std;

int getSmallestCnt(const string& word) {
    char smallest = numeric_limits<char>::max();
    for (auto c : word) {
        if (c < smallest)
            smallest = c;
    }
    return count(begin(word), end(word), smallest);
}

vector<int> numSmallerByFrequency(const vector<string>& queries, const vector<string>& words) {
    vector<int> smallestCnt;
    smallestCnt.reserve(words.size());
    for (const auto& word : words)
        smallestCnt.push_back(getSmallestCnt(word));
    sort(begin(smallestCnt), end(smallestCnt));
    vector<int> res;
    res.reserve(queries.size());
    for (const auto& query : queries) {
        int cnt = getSmallestCnt(query);
        auto biggerIt = upper_bound(begin(smallestCnt), end(smallestCnt), cnt);
        res.push_back(distance(biggerIt, end(smallestCnt)));
    }
    return res;
}

#endif //ALGORITHMICCHALLENGES_1170_COMPARESTRINGSBYFREQUENCYOFTHESMALLESTCHARACTER_H
