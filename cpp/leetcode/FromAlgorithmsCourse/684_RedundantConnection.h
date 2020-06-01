//https://leetcode.com/problems/redundant-connection/
#ifndef ALGORITHMICCHALLENGES_684_REDUNDANTCONNECTION_H
#define ALGORITHMICCHALLENGES_684_REDUNDANTCONNECTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int from_ = 0;
    int to_ = 0;
    size_t rank_ = 0;

    Edge(int from, int to, size_t rank) : from_{from}, to_{to}, rank_{rank}{}
};

struct EdgeComparator {
    bool operator()(Edge const& edge1, Edge const& edge2) noexcept {
        return edge1.rank_ > edge2.rank_;
    }
};

using EdgesT = vector<Edge>;
using GraphT = unordered_map<int, EdgesT>;
using VisitedT = unordered_set<int>;
using EdgeQueueT = priority_queue<Edge, vector<Edge>, EdgeComparator>;

vector<int> findRedundantConnection(vector<vector<int>> const& edges) {
    if (edges.empty())
        return {};

    GraphT graph;
    for (size_t i = 0; i != edges.size(); ++i) {
        graph[edges[i].front()].emplace_back(edges[i].front(), edges[i].back(), i);
        graph[edges[i].back()].emplace_back(edges[i].back(), edges[i].front(), i);
    }

    VisitedT visited;
    EdgeQueueT toVisit;
    visited.insert(edges.front().front());
    for (auto& edge : graph.at(edges.front().front())) {
        toVisit.push(edge);
    }

    while (!toVisit.empty()) {
        auto nextEdge = toVisit.top();
        toVisit.pop();
        if (visited.find(nextEdge.to_) != end(visited)) {
            vector<int> redundantEdge{nextEdge.from_, nextEdge.to_};
            if (find(begin(edges), end(edges), redundantEdge) != end(edges))
                return redundantEdge;
            return vector<int>{nextEdge.to_, nextEdge.from_};
        }
        visited.insert(nextEdge.to_);
        for (auto& edge : graph.at(nextEdge.to_)) {
            if (edge.to_ != nextEdge.from_) {
                toVisit.push(edge);
            }
        }
    }

    return {};
}

int getParent(vector<int>& parents, int vertice) {
    auto res = vertice;
    while (parents.at(res) != res) {
        parents[res] = parents[parents[res]];
        res = parents.at(res);
    }
    return res;
}

vector<int> findRedundantConnectionUnionFind(vector<vector<int>> const& edges) {
    vector<int> parents(edges.size() + 1);
    vector<size_t> sizes(edges.size() + 1, 1);
    std::iota(std::begin(parents), std::end(parents), 0);
    vector<int> redundantConnection;
    for (auto& edge : edges) {
        auto parentFrom = getParent(parents, edge.front());
        auto parentTo = getParent(parents, edge.back());
        if (parentFrom != parentTo) {
            if (sizes[parentFrom] < sizes[parentTo]) {
                parents[parentFrom] = parentTo;
                sizes[parentTo] += sizes[parentFrom];
            } else {
                parents[parentTo] = parentFrom;
                sizes[parentFrom] += sizes[parentTo];
            }
        } else {
            redundantConnection = edge;
        }
    }
    return redundantConnection;
}

#endif //ALGORITHMICCHALLENGES_684_REDUNDANTCONNECTION_H
