//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
#ifndef ALGORITHMICCHALLENGES_947_MOSTSTONESREMOVEDWITHSAMEROWORCOLUMN_H
#define ALGORITHMICCHALLENGES_947_MOSTSTONESREMOVEDWITHSAMEROWORCOLUMN_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <queue>
#include <numeric>
#include <algorithm>
using namespace std;

struct Point;
using PointsT = unordered_map<int, unordered_map<int, shared_ptr<Point>>>;

struct Point {
    unordered_set<Point*> connections_;
};

int removeStones(const vector<vector<int>>& stones) {
    int moves = 0;
    PointsT xPoints, yPoints;
    for (auto& stone : stones) {
        auto point = make_shared<Point>();
        for (auto& p : xPoints[stone.front()]) {
            p.second->connections_.insert(point.get());
            point->connections_.insert(p.second.get());
        }
        xPoints[stone.front()][stone.back()] = point;
        for (auto& p : yPoints[stone.back()]) {
            p.second->connections_.insert(point.get());
            point->connections_.insert(p.second.get());
        }
        yPoints[stone.back()][stone.front()] = move(point);
    }
    unordered_set<Point*> visited;
    for (auto& stone : stones) {
        auto point = xPoints[stone.front()][stone.back()].get();
        if (visited.find(point) == end(visited)) {
            queue<Point*> toProcess;
            toProcess.push(point);
            visited.insert(point);
            while (!toProcess.empty()) {
                auto p = toProcess.front();
                toProcess.pop();
                for (auto connection : p->connections_) {
                    if (visited.find(connection) == end(visited)) {
                        ++moves;
                        toProcess.push(connection);
                        visited.insert(connection);
                    }
                }
            }
        }
    }

    return moves;
}

size_t getComponent(size_t stone, vector<int>& components) {
    auto component = components[stone];
    while (component != stone) {
        auto parent = component;
        auto parentComponent = components[parent];
        components[stone] = parentComponent;
        stone = parent;
        component = parentComponent;
    }

    return component;
}

int removeStonesUnionFind(const vector<vector<int>>& stones) {
    vector<int> stoneComponents(stones.size());
    std::iota(begin(stoneComponents), end(stoneComponents), 0);
    vector<int> componentSizes(stones.size(), 1);
    unordered_multimap<int, size_t> xStones, yStones;
    for (size_t i = 0; i < stones.size(); ++i) {
        xStones.emplace(stones[i].front(), i);
        yStones.emplace(stones[i].back(), i);
    }

    unordered_set<size_t> visitedStones;
    for (size_t i = 0; i < stones.size(); ++i) {
        if (visitedStones.find(i) != end(visitedStones))
            continue;
        
        queue<size_t> toVisit;
        toVisit.push(i);
        while (!toVisit.empty()) {
            auto nextStone = toVisit.front();
            toVisit.pop();
            visitedStones.insert(nextStone);
            auto stoneComponent = getComponent(nextStone, stoneComponents);
            auto combineComponents = [&](auto range) {
                for (auto rIt = range.first; rIt != range.second; ++rIt) {
                    if (rIt->second == nextStone)
                        continue;

                    auto connectedComponent = getComponent(rIt->second, stoneComponents);
                    if (connectedComponent == stoneComponent)
                        continue;
                    
                    toVisit.push(rIt->second);
                    if (componentSizes[connectedComponent] < componentSizes[stoneComponent]) {
                        stoneComponents[connectedComponent] = stoneComponent;
                        componentSizes[stoneComponent] += componentSizes[connectedComponent];
                    } else {
                        stoneComponents[stoneComponent] = connectedComponent;
                        componentSizes[connectedComponent] += componentSizes[stoneComponent];
                        stoneComponent = connectedComponent;
                    }
                }
            };
            combineComponents(xStones.equal_range(stones[nextStone].front()));
            combineComponents(yStones.equal_range(stones[nextStone].back()));
        }
    }

    int res = 0;
    unordered_set<size_t> countedComponents;
    for (size_t i = 0; i < stones.size(); ++i) {
        auto component = getComponent(i, stoneComponents);
        if (countedComponents.find(component) == end(countedComponents)) {
            res += (componentSizes[component] - 1);
            countedComponents.insert(component);
        }
    }

    return res;
}

#endif //ALGORITHMICCHALLENGES_947_MOSTSTONESREMOVEDWITHSAMEROWORCOLUMN_H
