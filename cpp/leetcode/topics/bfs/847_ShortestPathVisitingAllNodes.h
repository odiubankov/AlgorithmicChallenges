#ifndef ALGORITHMICCHALLENGES_847_SHORTESTPATHVISITINGALLNODES_H
#define ALGORITHMICCHALLENGES_847_SHORTESTPATHVISITINGALLNODES_H

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct Move {
    int current;
    int visited;
    int steps;
};

int getAllVisitedMask(int cnt) {
    int allVisitedMask = 0;
    for (int i = 0; i != cnt; ++i) {
        allVisitedMask |= (1 << i);
    }
    return allVisitedMask;
}

int shortestPathLength(const vector<vector<int>>& graph) {
    const int allVisitedMask = getAllVisitedMask(graph.size());
    std::unordered_set<int> processed;
    std::queue<Move> q;
    for (int i = 0; i < graph.size(); ++i) {
        Move move{i, 1 << i, 0};
        q.emplace(move);

        int processedIndex = 1 << (13 + i);
        processedIndex |= (1 << i);
        processed.insert(processedIndex);
    }

    for (;;) {
        auto nextItem = q.front();
        if ((nextItem.visited & allVisitedMask) == allVisitedMask) {
            return nextItem.steps;
        }

        q.pop();
        for (auto connection : graph[nextItem.current]) {
            int processedIndex = nextItem.visited;
            processedIndex |= 1 << (13 + connection);
            processedIndex |= (1 << connection);
            if (processed.find(processedIndex) == end(processed)) {
                Move move{connection, nextItem.visited | (1 << connection), nextItem.steps + 1};
                q.emplace(move);
                processed.insert(processedIndex);
            }
        }
    }

    return -1;
}

#endif //ALGORITHMICCHALLENGES_847_SHORTESTPATHVISITINGALLNODES_H
