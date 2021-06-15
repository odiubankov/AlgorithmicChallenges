#ifndef ALGORITHMICCHALLENGES_1584_MINCOSTTOCONNECTALLPOINTS_H
#define ALGORITHMICCHALLENGES_1584_MINCOSTTOCONNECTALLPOINTS_H

#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

struct Edge {
    size_t from_;
    size_t to_;
    int distance_;

    Edge(size_t from, size_t to, int distance)
        : from_{from}
        , to_{to}
        , distance_{distance}
    {}

    bool operator>(const Edge& other) const {
        return distance_ > other.distance_;
    }
};

using EdgesT = priority_queue<Edge, vector<Edge>, greater<Edge>>;
using MstVerticesT = unordered_set<size_t>;
using QueuedEdgesT = unordered_set<string>;
using PointsT = vector<vector<int>>;

void addVertice(size_t to,
             int length,
             const PointsT& points,
             EdgesT& edges,
             MstVerticesT& mstVertices,
             QueuedEdgesT& queuedEdges,
             int& totalLength) {
    totalLength += length;
    mstVertices.insert(to);
    for (size_t i = 0; i < points.size(); ++i) {
        if (mstVertices.find(i) != end(mstVertices)) {
            continue;
        }

        const string edgeKey = to_string(min(i, to)) + "," + to_string(max(i, to));
        if (queuedEdges.find(edgeKey) != end(queuedEdges)) {
            continue;
        }

        int distance = abs(points[to].front() - points[i].front()) +
                       abs(points[to].back() - points[i].back());
        edges.emplace(to, i, distance);
        queuedEdges.insert(edgeKey);
    }
}

int minCostConnectPoints(const PointsT& points) {
    EdgesT edges;
    MstVerticesT mstVertices;
    QueuedEdgesT queuedEdges;

    int totalLength = 0;
    addVertice(0, 0, points, edges, mstVertices, queuedEdges, totalLength);
    while (mstVertices.size() < points.size()) {
        auto nextEdge = edges.top();
        edges.pop();
        if (mstVertices.find(nextEdge.to_) == end(mstVertices)) {
            addVertice(nextEdge.to_, nextEdge.distance_, points, edges, mstVertices, queuedEdges, totalLength);
        }
    }

    return totalLength;
}

#endif //ALGORITHMICCHALLENGES_1584_MINCOSTTOCONNECTALLPOINTS_H
