//https://leetcode.com/problems/find-and-replace-in-string/
#ifndef ALGORITHMICCHALLENGES_833_FINDANDREPLACEINSTRING_H
#define ALGORITHMICCHALLENGES_833_FINDANDREPLACEINSTRING_H
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

struct Replacement{
    string from;
    string to;
};

string findReplaceString(string S, const vector<int>& indexes, const vector<string>& sources, const vector<string>& targets) {
    map<int, Replacement> replacements;
    for (size_t i = 0; i < indexes.size(); ++i) {
        auto substr = S.substr(indexes[i], min(sources[i].length(), S.length() - indexes[i]));
        if (substr == sources[i])
            replacements.emplace(indexes[i], Replacement{sources[i], targets[i]});
    }
    if (replacements.empty())
        return S;

    vector<string> resParts;
    auto replacementIt = rbegin(replacements);
    if ((replacementIt->first + replacementIt->second.from.length()) < S.length())
        resParts.push_back(S.substr(replacementIt->first + replacementIt->second.from.length()));
    resParts.push_back(replacementIt->second.to);
    auto prevIt = replacementIt;
    ++replacementIt;
    for (;replacementIt != rend(replacements); ++replacementIt) {
        auto replaceUntil = replacementIt->first + replacementIt->second.from.length();
        resParts.push_back(S.substr(replaceUntil, prevIt->first - replaceUntil));
        resParts.push_back(replacementIt->second.to);
        prevIt = replacementIt;
    }
    resParts.push_back(S.substr(0, prevIt->first));
    stringstream ss;
    for (auto partIt = rbegin(resParts); partIt != rend(resParts); ++partIt)
        ss << *partIt;
    return ss.str();
}

#endif //ALGORITHMICCHALLENGES_833_FINDANDREPLACEINSTRING_H
