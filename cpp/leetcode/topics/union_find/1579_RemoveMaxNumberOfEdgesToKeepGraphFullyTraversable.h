#ifndef ALGORITHMICCHALLENGES_1579_REMOVEMAXNUMBEROFEDGESTOKEEPGRAPHFULLYTRAVERSABLE_H
#define ALGORITHMICCHALLENGES_1579_REMOVEMAXNUMBEROFEDGESTOKEEPGRAPHFULLYTRAVERSABLE_H

#include <vector>

using namespace std;

struct Components {
    vector<int> parents;
    vector<int> sizes;
    int cnt;
};

Components createComponents(int cnt) {
    Components components;
    components.cnt = cnt;
    for (int i = 0; i < cnt; ++i) {
        components.parents.push_back(i);
        components.sizes.push_back(1);
    }

    return components;
}

using EdgeT = vector<int>;
bool isTraversableByBobAndAlice(const EdgeT& edge) {
    return edge.front() == 3;
}

bool isTraversableOnlyByBob(const EdgeT& edge) {
    return edge.front() == 1;
}

bool isTraversableOnlyByAlice(const EdgeT& edge) {
    return edge.front() == 2;
}

int getParentComponent(vector<int>& parents, int id) {
    --id;
    while (parents[id] != id) {
        id = parents[id];
        parents[id] = parents[parents[id]];
    }

    return id;
}

void unionComponents(Components& components, int first, int second) {
    if (components.sizes[first] < components.sizes[second]) {
        components.parents[first] = components.parents[second];
        components.sizes[second] += components.sizes[first];
    } else {
        components.parents[second] = components.parents[first];
        components.sizes[first] += components.sizes[second];
    }
    --components.cnt;
}

int maxNumEdgesToRemove(int n, const vector<vector<int>>& edges) {
    auto aliceComponents = createComponents(n);
    auto bobComponents = aliceComponents;
    int notUsedEdgesCnt = 0;
    for (auto& edge : edges) {
        if (isTraversableByBobAndAlice(edge)) {
            auto parent1 = getParentComponent(aliceComponents.parents, edge[1]);
            auto parent2 = getParentComponent(aliceComponents.parents, edge[2]);
            if (parent1 == parent2) {
                ++notUsedEdgesCnt;
                // no need to check Bobs components since they're same now
            } else {
                unionComponents(aliceComponents, parent1, parent2);
                unionComponents(bobComponents, parent1, parent2);
            }
        }
    }

    for (auto& edge : edges) {
        if (isTraversableOnlyByBob(edge)) {
            auto parent1 = getParentComponent(bobComponents.parents, edge[1]);
            auto parent2 = getParentComponent(bobComponents.parents, edge[2]);
            if (parent1 == parent2) {
                ++notUsedEdgesCnt;
                // no need to check Bobs components since they're same now
            } else {
                unionComponents(bobComponents, parent1, parent2);
            }
        } else if (isTraversableOnlyByAlice(edge)) {
            auto parent1 = getParentComponent(aliceComponents.parents, edge[1]);
            auto parent2 = getParentComponent(aliceComponents.parents, edge[2]);
            if (parent1 == parent2) {
                ++notUsedEdgesCnt;
                // no need to check Bobs components since they're same now
            } else {
                unionComponents(aliceComponents, parent1, parent2);
            }
        }
    }

    if (aliceComponents.cnt > 1 && bobComponents.cnt > 1)
        return -1;

    return notUsedEdgesCnt;
}

#endif //ALGORITHMICCHALLENGES_1579_REMOVEMAXNUMBEROFEDGESTOKEEPGRAPHFULLYTRAVERSABLE_H
