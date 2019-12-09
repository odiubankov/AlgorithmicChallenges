//https://leetcode.com/problems/evaluate-division/
#ifndef ALGORITHMICCHALLENGES_399_EVALUATEDIVISION_H
#define ALGORITHMICCHALLENGES_399_EVALUATEDIVISION_H

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

using WordIndexesT = unordered_map<string, size_t>;

void addWord(const string& word, WordIndexesT& wordIndexes, size_t& index) {
    auto wordIt = wordIndexes.find(word);
    if (wordIt == end(wordIndexes))
        wordIndexes[word] = index++;
}

vector<double> calcEquation(const vector<vector<string>>& equations, const vector<double>& values, const vector<vector<string>>& queries) {
    size_t index = 0;
    WordIndexesT wordIndexes;
    for (const auto& equation : equations) {
        addWord(equation.front(), wordIndexes, index);
        addWord(equation.back(), wordIndexes, index);
    }
    vector<unordered_map<size_t, double>> graph(index);
    for (size_t i = 0; i < equations.size(); ++i) {
        auto var1 = wordIndexes[equations[i].front()];
        auto var2 = wordIndexes[equations[i].back()];
        graph[var1][var2] = values[i];
        graph[var2][var1] = 1.0 / values[i];
    }
    vector<double> res(queries.size(), -1.0);
    for (size_t i = 0; i < queries.size(); ++i) {
        auto word1It = wordIndexes.find(queries[i].front());
        auto word2It = wordIndexes.find(queries[i].back());
        if (word1It == end(wordIndexes) || word2It == end(wordIndexes))
            continue;
        auto var1 = word1It->second;
        auto var2 = word2It->second;
        queue<pair<size_t, double>> toVisit;
        toVisit.emplace(var1, 1.0);
        vector<char> visited(graph.size(), 0);
        visited[var1] = 1;
        while (!toVisit.empty()) {
            auto next = toVisit.front();
            toVisit.pop();
            if (next.first == var2) {
                res[i] = next.second;
                break;
            }
            for (const auto& edge : graph[next.first]) {
                if (visited[edge.first] == 0) {
                    toVisit.emplace(edge.first, next.second * edge.second);
                    visited[edge.first] = 1;
                }
            }
        }
    }
    return res;
}

#endif //ALGORITHMICCHALLENGES_399_EVALUATEDIVISION_H
