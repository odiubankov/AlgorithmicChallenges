//https://leetcode.com/problems/critical-connections-in-a-network/
//Tarjan algorithm

#ifndef ALGORITHMICCHALLENGES_1192_CRITICALCONNECTIONSINNETWORK_H
#define ALGORITHMICCHALLENGES_1192_CRITICALCONNECTIONSINNETWORK_H

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;

using GraphT = vector<vector<int>>;
using VisitedT = vector<bool>;
using ConnectionT = vector<int>;
using PathT = vector<int>;
using ComponentsT = vector<int>;
using ItemRanksT = vector<int>;

GraphT fillGraph(int n, vector<ConnectionT> const& connections) {
    GraphT graph(n);
    for (auto& connection : connections) {
        graph[connection.front()].push_back(connection.back());
        graph[connection.back()].push_back(connection.front());
    }
    return graph;
}

void dfs(PathT path, VisitedT& visited, VisitedT& cycleVisited,
         ComponentsT& components, GraphT const& graph) {
    int currentServer = path.back();
    if (cycleVisited[currentServer]) {
        for (auto it = rbegin(path) + 1; components[*it] != components[currentServer]; ++it) {
            components[*it] = components[currentServer];
        }
        return;
    }

    if (visited[currentServer]) {
        return;
    }

    visited[currentServer] = true;
    cycleVisited[currentServer] = true;
    for (auto connection : graph[currentServer]) {
        if (path.size() == 1 || connection != path[path.size() - 2]) {
            PathT connectionPath = path;
//TODO replace copying to pop_back
            connectionPath.push_back(connection);
            dfs(connectionPath, visited, cycleVisited, components, graph);
        }
    }
    cycleVisited[currentServer] = false;
}

vector<vector<int>> criticalConnections(int n, vector<ConnectionT> const& connections) {
    if (connections.empty())
        return {};

    auto graph = fillGraph(n, connections);
    ComponentsT components(n);
    for (size_t i = 0; i != n; ++i)
        components[i] = i;
    VisitedT visited(n, false), cycleVisited(n, false);
    dfs({0}, visited, cycleVisited, components, graph);
    vector<vector<int>> criticalConnections;
    for (auto& connection : connections) {
        if (components[connection.front()] != components[connection.back()]) {
            criticalConnections.push_back(connection);
        }
    }

    return criticalConnections;
}

void tarjanDfs(
        int item, int prevItem, GraphT const& graph,
        int& currentRank, ItemRanksT& discoveryRanks, ItemRanksT& lowRanks,
        vector<ConnectionT>& criticalConnections) {
    lowRanks[item] = discoveryRanks[item] = currentRank++;
    for (auto connection : graph.at(item)) {
        if (connection == prevItem)
            continue;
        if (discoveryRanks[connection] == -1) {
            tarjanDfs(connection, item, graph, currentRank, discoveryRanks, lowRanks, criticalConnections);
            lowRanks[item] = min(lowRanks[item], lowRanks[connection]);
            if (discoveryRanks[item] < lowRanks[connection])
                criticalConnections.push_back({item, connection});
        } else {
            lowRanks[item] = min(lowRanks[item], discoveryRanks[connection]);
        }
    }
}

vector<ConnectionT> criticalConnectionsTarjan(int n, vector<ConnectionT> const& connections) {
    if (connections.empty())
        return {};

    auto graph = fillGraph(n, connections);
    ItemRanksT discoveryRanks(n, -1), lowRanks(n, -1);
    int currentRank = 0;
    vector<ConnectionT> criticalConnections;
    for (int i = 0; i != n; ++i) {
        if (discoveryRanks[i] == -1) {
            tarjanDfs(i, -1, graph, currentRank, discoveryRanks, lowRanks, criticalConnections);
        }
    }

    return criticalConnections;
}

#endif //ALGORITHMICCHALLENGES_1192_CRITICALCONNECTIONSINNETWORK_H
