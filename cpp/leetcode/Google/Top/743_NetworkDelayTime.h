//https://leetcode.com/problems/network-delay-time/
#ifndef ALGORITHMICCHALLENGES_743_NETWORKDELAYTIME_H
#define ALGORITHMICCHALLENGES_743_NETWORKDELAYTIME_H

#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

using NodeDistanceT = pair<int, int>;
struct NodeDistanceComp {
    bool operator()(const NodeDistanceT& node1, const NodeDistanceT& node2) const {
        return node1.first > node2.first;
    }
};

using NodesQueueT = priority_queue<NodeDistanceT, vector<NodeDistanceT>, NodeDistanceComp>;

int networkDelayTime(const vector<vector<int>>& times, int N, int K) {
    vector<vector<pair<int , int>>> connections(N);
    for (auto& time : times)
        connections[time[0] - 1].push_back(make_pair(time[1] - 1, time[2]));
    NodesQueueT nodesQueue;
    nodesQueue.emplace(0, K - 1);
    vector<bool> visited(N, false);
    int maxDistance = 0;
    while (!nodesQueue.empty()) {
        auto next = nodesQueue.top();
        nodesQueue.pop();
        if (visited[next.second])
            continue;
        visited[next.second] = true;
        maxDistance = max(maxDistance, next.first);
        for (const auto& connection : connections[next.second])
            nodesQueue.emplace(next.first + connection.second, connection.first);
    }
    return all_of(begin(visited), end(visited), [](auto item) { return item; }) ? maxDistance : -1;
}

#endif //ALGORITHMICCHALLENGES_743_NETWORKDELAYTIME_H


