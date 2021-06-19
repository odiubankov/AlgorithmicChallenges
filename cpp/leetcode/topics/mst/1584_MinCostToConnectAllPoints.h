//https://leetcode.com/problems/min-cost-to-connect-all-points/
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

struct Point {
    size_t index_;
    int weight_;

    bool operator>(const Point& other) const {
        return weight_ > other.weight_;
    }
};

int minCostConnectPointsPrimMST(const PointsT& points) {
    vector<bool> inMST(points.size(), false);
    size_t inMstCnt = 0;
    vector<int> weights(points.size(), numeric_limits<int>::max());
    std::priority_queue<Point, vector<Point>, greater<Point>> q;
    int totalWeight = 0;
    q.emplace(Point{0, 0});
    for (;;) {
        auto p = q.top();
        q.pop();
        if (inMST[p.index_])
            continue;

        totalWeight += p.weight_;
        ++inMstCnt;
        if (inMstCnt == points.size())
            return  totalWeight;
        inMST[p.index_] = true;

        for (size_t i = 0; i < points.size(); ++i) {
            if (inMST[i])
                continue;

            int weight = abs(points[i].front() - points[p.index_].front());
            weight += abs(points[i].back() - points[p.index_].back());

            if (weight >= weights[i])
                continue;

            weights[i] = weight;
            q.emplace(Point{i, weight});
        }
    }

    return 0;
}

int getParent(vector<int>& components, int i) {
    while (components[i] != i) {
        int parent = components[i];
        components[i] = components[components[i]];
        i = parent;
    }

    return i;
}

int minCostConnectPointsKruskalMST(const PointsT& points) {
    vector<vector<int>> edges;
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            int edgeWeight = abs(points[i].front() - points[j].front());
            edgeWeight += abs(points[i].back() - points[j].back());
            edges.emplace_back(vector<int>{edgeWeight, i, j});
        }
    }

    sort(begin(edges), end(edges), [](const auto& e1, const auto& e2) { return e1.front() < e2.front(); });
    vector<int> components(points.size());
    for (int i = 0; i < points.size(); ++i)
        components[i] = i;
    vector<int> sizes(points.size(), 1);
    int totalWeight = 0;
    for (const auto& e : edges) {
        int leftParent = getParent(components, e[1]);
        int rightParent = getParent(components, e[2]);
        if (leftParent != rightParent) {
            totalWeight += e[0];
            if (sizes[leftParent] < sizes[rightParent]) {
                sizes[rightParent] += sizes[leftParent];
                if (sizes[rightParent] == points.size())
                    break;
                components[leftParent] = rightParent;
            } else {
                sizes[leftParent] += sizes[rightParent];
                if (sizes[leftParent] == points.size())
                    break;
                components[rightParent] = leftParent;
            }
        }
    }

    return totalWeight;
}

#endif //ALGORITHMICCHALLENGES_1584_MINCOSTTOCONNECTALLPOINTS_H
