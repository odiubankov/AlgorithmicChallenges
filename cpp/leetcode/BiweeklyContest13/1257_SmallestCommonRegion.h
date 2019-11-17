//https://leetcode.com/contest/biweekly-contest-13/problems/smallest-common-region/
#ifndef ALGORITHMICCHALLENGES_1257_SMALLESTCOMMONREGION_H
#define ALGORITHMICCHALLENGES_1257_SMALLESTCOMMONREGION_H

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

using ParentsT = unordered_map<string, string>;
using VisitedT = unordered_set<string>;
bool checkParentAndGoUp(const ParentsT& parents, VisitedT& visited, ParentsT::const_iterator& pIt) {
    if (pIt == end(parents))
        return false;
    if (visited.find(pIt->second) != end(visited))
        return true;
    visited.insert(pIt->second);
    pIt = parents.find(pIt->second);
    return false;
}

string findSmallestRegion(const vector<vector<string>>& regions, const string& region1, const string& region2) {
    ParentsT parents;
    for (auto& r : regions) {
        for (auto p = begin(r) + 1; p != end(r); ++p)
            parents[*p] = r.front();
    }

    vector<ParentsT::const_iterator> parentIts;
    VisitedT visited;
    for (const auto& region : {region1, region2}) {
        visited.insert(region);
        parentIts.emplace_back(parents.find(region));
    }
    auto notEqualEnd = [&parents](auto& parentIt) { return parentIt != end(parents); };
    while (any_of(begin(parentIts), end(parentIts), notEqualEnd)) {
        for (auto& parentIt : parentIts) {
            if (checkParentAndGoUp(parents, visited, parentIt))
                return parentIt->second;
        }
    }
    return "";
}

#endif //ALGORITHMICCHALLENGES_1257_SMALLESTCOMMONREGION_H
