//https://leetcode.com/problems/minimum-height-trees/
#ifndef ALGORITHMICCHALLENGES_310_MINIMUMHEIGHTTREES_H
#define ALGORITHMICCHALLENGES_310_MINIMUMHEIGHTTREES_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using VerticeConnectionsT = vector<size_t>;
using GraphT = vector<VerticeConnectionsT>;
using VerticeItT = GraphT::const_iterator;
using PathT = vector<int>;

PathT getRemotestVerticePath(GraphT const& graph, size_t vertice, size_t prevVertice = numeric_limits<size_t>::max()) {
    PathT remotestVerticePath;
    for (auto connection : graph[vertice]) {
        if (connection != prevVertice) {
            auto connectionPath = getRemotestVerticePath(graph, connection, vertice);
            if (connectionPath.size() > remotestVerticePath.size()) {
                remotestVerticePath = move(connectionPath);
            }
        }
    }

    PathT path;
    path.push_back(vertice);
    move(begin(remotestVerticePath), end(remotestVerticePath), back_inserter(path));
    return path;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>> const& edges) {
    if (n == 0)
        return {};

    GraphT graph(n);
    for (auto & edge : edges) {
        graph[edge.front()].push_back(edge.back());
        graph[edge.back()].push_back(edge.front());
    }

    auto remotestVertice1 = getRemotestVerticePath(graph, 0);
    auto remotestVertice2 = getRemotestVerticePath(graph, remotestVertice1.back());
    vector<int> res{remotestVertice2[remotestVertice2.size() / 2]};
    if (remotestVertice2.size() % 2 == 0) {
        res.push_back(remotestVertice2[remotestVertice2.size() / 2 - 1]);
    }
    return res;
}

#endif //ALGORITHMICCHALLENGES_310_MINIMUMHEIGHTTREES_H
