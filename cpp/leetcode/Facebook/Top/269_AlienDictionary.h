//https://leetcode.com/problems/alien-dictionary/
#ifndef ALGORITHMICCHALLENGES_269_ALIENDICTIONARY_H
#define ALGORITHMICCHALLENGES_269_ALIENDICTIONARY_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

using NodesT = unordered_map<char, unordered_set<char>>;
using VisitedT = unordered_set<char>;
using CharStackT = stack<char>;

void addWordChars(const string& word, NodesT& nodes) {
    for (auto c : word) {
        auto it = nodes.find(c);
        if (it == end(nodes))
            nodes.emplace(c, unordered_set<char>{});
    }
}

bool nodesTopologicalSort(
    char node,
    const NodesT& nodes,
    VisitedT& visited,
    VisitedT& iterationChars,
    CharStackT& orderedChars) {
    for (auto child : nodes.at(node)) {
        if (visited.find(child) == end(visited)) {
            visited.insert(child);
            iterationChars.insert(child);
            if (!nodesTopologicalSort(child, nodes, visited, iterationChars, orderedChars))
                return false;
        } else {
            if (iterationChars.find(child) != end(iterationChars))
                return false;
        }
    }
    orderedChars.push(node);
    return true;
}

string alienOrder(const vector<string>& words) {
    if (words.empty())
        return {};
    NodesT nodes;
    auto wordIt = begin(words);
    addWordChars(*wordIt, nodes);
    auto prevWordIt = wordIt;
    ++wordIt;
    for (; wordIt != end(words); ++wordIt, ++prevWordIt) {
        addWordChars(*wordIt, nodes);
        auto charItPrev = begin(*prevWordIt);
        auto charItCurrent = begin(*wordIt);
        do {
            if (*charItCurrent != *charItPrev) {
                nodes[*charItPrev].insert(*charItCurrent);
                break;
            }
            ++charItPrev;
            ++charItCurrent;
        } while (charItPrev != end(*(prevWordIt)) && charItCurrent != end(*wordIt));
    }
    CharStackT orderedChars;
    VisitedT visited;
    for (const auto& node : nodes) {
        if (visited.find(node.first) != end(visited))
            continue;
        visited.insert(node.first);
        VisitedT iterationChars;
        iterationChars.insert(node.first);
        if (!nodesTopologicalSort(node.first, nodes, visited, iterationChars, orderedChars))
            return {};
    }
    string res;
    res.reserve(orderedChars.size());
    while (!orderedChars.empty()) {
        res.push_back(orderedChars.top());
        orderedChars.pop();
    }
    return res;
}

#endif //ALGORITHMICCHALLENGES_269_ALIENDICTIONARY_H
