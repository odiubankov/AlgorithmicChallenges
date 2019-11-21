//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
#ifndef ALGORITHMICCHALLENGES_947_MOSTSTONESREMOVEDWITHSAMEROWORCOLUMN_H
#define ALGORITHMICCHALLENGES_947_MOSTSTONESREMOVEDWITHSAMEROWORCOLUMN_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <queue>
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

#endif //ALGORITHMICCHALLENGES_947_MOSTSTONESREMOVEDWITHSAMEROWORCOLUMN_H
