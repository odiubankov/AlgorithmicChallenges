//https://leetcode.com/problems/the-skyline-problem/
#ifndef ALGORITHMICCHALLENGES_218_THESKYLINEPROBLEM_H
#define ALGORITHMICCHALLENGES_218_THESKYLINEPROBLEM_H

#include <vector>
#include <map>
#include <set>
#include <limits>
using namespace std;

void updateSkyline(vector<vector<int>>& skyline, const multiset<int>& h, int x) {
    if (skyline.empty()) {
        skyline.emplace_back(vector<int>{x, *rbegin(h)});
    } else if (h.empty()) {
        skyline.emplace_back(vector<int>{x, 0});
    } else if (skyline.back()[1] != *rbegin(h)) {
        skyline.emplace_back(vector<int>{x, *rbegin(h)});
    }
}

vector<vector<int>> getSkyline(const vector<vector<int>>& buildings) {
    if (buildings.empty())
        return {};
    auto bIt = begin(buildings), bItE = end(buildings);
    int x = (*bIt)[0];
    multimap<int, int> bEnds;
    vector<vector<int>> skyline;
    multiset<int> h;
    while (bIt != bItE || !bEnds.empty()) {
        if (bIt != bItE) {
            const auto& b = *bIt;
            if (b[0] == x) {
                h.insert(b[2]);
                bEnds.emplace(b[1], b[2]);
                ++bIt;
                continue;
            }
        }
        if (!bEnds.empty()) {
            auto nextEnd = begin(bEnds);
            if (nextEnd->first == x) {
                h.erase(h.find(nextEnd->second));
                bEnds.erase(nextEnd);
                continue;
            }
        }
        updateSkyline(skyline, h, x);
        if (bEnds.empty()) {
            if (bIt != bItE)
                x = (*bIt)[0];
        } else {
            auto nextEnd = begin(bEnds);
            x = bIt == bItE ? nextEnd->first : min((*bIt)[0], nextEnd->first);
        }
    }
    updateSkyline(skyline, h, x);
    return skyline;
}


#endif //ALGORITHMICCHALLENGES_218_THESKYLINEPROBLEM_H
