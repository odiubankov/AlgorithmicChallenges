//https://leetcode.com/problems/the-skyline-problem/
#ifndef ALGORITHMICCHALLENGES_218_THESKYLINEPROBLEM_H
#define ALGORITHMICCHALLENGES_218_THESKYLINEPROBLEM_H

#include <vector>
#include <map>
#include <set>
#include <limits>
#include <queue>
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

struct BuildingEnd {
    int x_ = 0;
    int height_ = 0;
    BuildingEnd(int x, int height) : x_{x}, height_{height} {}
};

struct BuildingEndComp {
    bool operator()(const BuildingEnd& l, const BuildingEnd& r) {
        return l.x_ > r.x_;
    }
};

using BuidingEndsT = priority_queue<BuildingEnd, vector<BuildingEnd>, BuildingEndComp>;

vector<vector<int>> getSkyline(const vector<vector<int>>& buildings) {
    if (buildings.empty())
        return {};
    BuidingEndsT bEnds;
    multiset<int> heigthes;
    int skylineX = buildings.front().front();
    vector<vector<int>> skyline;
    for (auto bIt = begin(buildings); bIt != end(buildings) || !bEnds.empty();) {
        if (bIt != end(buildings)) {
            const auto& building = *bIt;
            if (building.front() == skylineX) {
                heigthes.insert(building.back());
                bEnds.emplace(building[1], building[2]);
                ++bIt;
                continue;
            }
        }

        if (!bEnds.empty()) {
            auto nextEnd = bEnds.top();
            if (bEnds.top().x_ == skylineX) {
                heigthes.erase(heigthes.find(bEnds.top().height_));
                bEnds.pop();
                continue;
            }
        }

        updateSkyline(skyline, heigthes, skylineX);
        if (bEnds.empty()) {
            if (bIt != end(buildings))
                skylineX = bIt->front();
        } else {
            if (bIt == end(buildings))
                skylineX = bEnds.top().x_;
            else
                skylineX = min(bIt->front(), bEnds.top().x_);
        }
    }

    updateSkyline(skyline, heigthes, skylineX);
    return skyline;
}

#endif //ALGORITHMICCHALLENGES_218_THESKYLINEPROBLEM_H
