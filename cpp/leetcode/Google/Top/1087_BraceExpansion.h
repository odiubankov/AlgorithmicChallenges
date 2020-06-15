//https://leetcode.com/problems/brace-expansion/
#ifndef ALGORITHMICCHALLENGES_1087_BRACEEXPANSION_H
#define ALGORITHMICCHALLENGES_1087_BRACEEXPANSION_H

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

class WordDelimitedByComma : public string
{};

istream& operator>>(istream& is, WordDelimitedByComma& output) {
    getline(is, output, ',');
    return is;
}

vector<string> getCombinations(
    const vector<vector<string>>::const_iterator it,
    const vector<vector<string>>::const_iterator itE) {
    if (it + 1 == itE)
        return *it;
    auto nextCombinations = getCombinations(it + 1, itE);
    vector<string> res;
    for (auto strIt = begin(*it); strIt != end(*it); ++strIt) {
        for (auto nextIt = begin(nextCombinations); nextIt != end(nextCombinations); ++nextIt)
            res.push_back(*strIt + *nextIt);
    }
    return res;
}

vector<string> expand(string S) {
    vector<vector<string>> parts;
    size_t pos = 0;
    while (pos != S.length()) {
        size_t openBlock = S.find('{', pos);
        if (openBlock == string::npos || openBlock > pos) {
            if (openBlock == string::npos)
                openBlock = S.length();
            parts.push_back({S.substr(pos, openBlock - pos)});
            pos = openBlock;
        } else {
            size_t closeBlock = S.find('}', openBlock);
            string block = S.substr(openBlock + 1, closeBlock - openBlock - 1);
            istringstream iss{block};
            parts.emplace_back(istream_iterator<WordDelimitedByComma>{iss},
                istream_iterator<WordDelimitedByComma>{});
            pos = closeBlock + 1;
        }
    }
    for (auto& part : parts) {
        sort(begin(part), end(part));
    }
    auto combinations = getCombinations(begin(parts), end(parts));
    return combinations;
}

#endif //ALGORITHMICCHALLENGES_1087_BRACEEXPANSION_H
