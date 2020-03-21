//https://leetcode.com/problems/k-closest-points-to-origin/
#ifndef ALGORITHMICCHALLENGES_973_KCLOSESTPOINTSTOORIGIN_H
#define ALGORITHMICCHALLENGES_973_KCLOSESTPOINTSTOORIGIN_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

struct Point {
    vector<int> coord;
    double originDist = 0.0;
    explicit Point(vector<int> coord_)
     : coord{move(coord_)} {
        originDist = sqrt(static_cast<double>(pow(abs(coord.front()),2) +
                                              pow(abs(coord.back()), 2)));
    }
};

struct OriginDistComp {
    bool operator()(const Point& p1, const Point& p2) {
        return p1.originDist < p2.originDist;
    }
};

vector<vector<int>> kClosest(const vector<vector<int>>& points, int K) {
    if (K == 0)
        return {};
    vector<Point> closestPoints;
    closestPoints.reserve(K + 1);
    auto coordIt = begin(points) + K;
    transform(begin(points), coordIt, back_inserter(closestPoints),
        [](auto coord) { return Point{move(coord)}; } );
    auto originDistComp = [](const Point& p1, const Point& p2) {
        return p1.originDist < p2.originDist;
    };
    make_heap(begin(closestPoints), end(closestPoints), originDistComp);
    for_each(coordIt, end(points),
        [&closestPoints, &originDistComp](auto coord) {
            closestPoints.emplace_back(move(coord));
            push_heap(begin(closestPoints), end(closestPoints), originDistComp);
            pop_heap(begin(closestPoints), end(closestPoints), originDistComp);
            closestPoints.pop_back();
        });
    vector<vector<int>> closestCoord;
    closestCoord.reserve(K);
    transform(begin(closestPoints), end(closestPoints), back_inserter(closestCoord),
        [](const auto& point) { return point.coord; } );
    return closestCoord;
}

vector<vector<int>> kClosestQueue(const vector<vector<int>>& points, int K) {
    priority_queue<Point, vector<Point>, OriginDistComp> closestPoints;
    for (size_t i = 0; i != K; ++i) {
        closestPoints.emplace(points[i]);
    }
    for (size_t i = K; i != points.size(); ++i) {
        closestPoints.emplace(points[i]);
        closestPoints.pop();
    }
    vector<vector<int>> closestCoord;
    closestCoord.reserve(K);
    while (!closestPoints.empty()) {
        closestCoord.push_back(move(closestPoints.top().coord));
        closestPoints.pop();
    }
    return closestCoord;
}

#endif //ALGORITHMICCHALLENGES_973_KCLOSESTPOINTSTOORIGIN_H
