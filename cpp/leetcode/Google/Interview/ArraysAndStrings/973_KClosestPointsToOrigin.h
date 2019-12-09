//https://leetcode.com/problems/k-closest-points-to-origin/
#ifndef ALGORITHMICCHALLENGES_973_KCLOSESTPOINTSTOORIGIN_H
#define ALGORITHMICCHALLENGES_973_KCLOSESTPOINTSTOORIGIN_H

#include <vector>
#include <cmath>
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

#endif //ALGORITHMICCHALLENGES_973_KCLOSESTPOINTSTOORIGIN_H
