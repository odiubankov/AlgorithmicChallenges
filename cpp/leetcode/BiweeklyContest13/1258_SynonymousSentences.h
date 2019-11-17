//https://leetcode.com/contest/biweekly-contest-13/problems/synonymous-sentences/
#ifndef ALGORITHMICCHALLENGES_1258_SYNONYMOUSSENTENCES_H
#define ALGORITHMICCHALLENGES_1258_SYNONYMOUSSENTENCES_H

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

unordered_set<string> getAllSynonyms(const unordered_map<string, vector<string>>& synonyms, const string& word) {
    unordered_set<string> visited;
    queue<string> toVisit;
    toVisit.push(word);
    visited.insert(word);
    while (!toVisit.empty()) {
        auto next = toVisit.front();
        toVisit.pop();
        auto nextSynonyms = synonyms.find(next);
        if (nextSynonyms != end(synonyms)) {
            for (const auto& synonym : nextSynonyms->second) {
                if (visited.find(synonym) == end(visited)) {
                    toVisit.push(synonym);
                    visited.insert(synonym);
                }
            }
        }
    }
    return visited;
}

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
        tokens.push_back(token);
    return tokens;
}

vector<string> getCombinations(const vector<string>::const_iterator& it, const vector<string>::const_iterator& itE, const unordered_map<string, vector<string>>& synonMap) {
    if (it == itE)
        return {""};
    vector<string> res;
    auto itCombinations = getAllSynonyms(synonMap, *it);
    for (const auto& comb : itCombinations) {
        for (const auto& nextComb : getCombinations(it + 1, itE, synonMap))
            res.push_back(nextComb.empty() ? comb : comb + " " + nextComb);
    }
    return res;
}

vector<string> generateSentences(const vector<vector<string>>& synonyms, const string& text) {
    unordered_map<string, vector<string>> synonMap;
    for (const auto& syn : synonyms) {
        synonMap[syn.front()].push_back(syn.back());
        synonMap[syn.back()].push_back(syn.front());
    }

    auto words = split(text, ' ');
    auto res = getCombinations(begin(words), end(words), synonMap);
    sort(begin(res), end(res));
    return res;
}

#endif //ALGORITHMICCHALLENGES_1258_SYNONYMOUSSENTENCES_H
