//https://leetcode.com/problems/friend-circles/description/
#ifndef ALGORITHMICCHALLENGES_547_FRIENDCIRCLES_H
#define ALGORITHMICCHALLENGES_547_FRIENDCIRCLES_H

#include <vector>
#include <numeric>

using namespace std;

int getParent(vector<int>& parents, int i) {
    while (parents[i] != i) {
        parents[i] = parents[parents[i]];
        i = parents[i];
    }
    return i;
}

int findCircleNum(vector<vector<int>> const& M) {
    vector<int> parents(M.size());
    std::iota(std::begin(parents), std::end(parents), 0);
    vector<size_t> sizes(M.size(), 1);
    for (size_t i = 0; i != M.size(); ++i) {
        for (size_t j = 0; j != M[i].size(); ++j) {
            if (M[i][j] == 1) {
                auto parentI = getParent(parents, i);
                auto parentJ = getParent(parents, j);
                if (parentI != parentJ) {
                    if (sizes[parentI] < sizes[parentJ]) {
                        parents[parentI] = parentJ;
                        sizes[parentJ] += sizes[parentI];
                    } else {
                        parents[parentJ] = parentI;
                        sizes[parentI] += sizes[parentJ];
                    }
                }
            }
        }
    }

    int circlesCnt = 0;
    for (int i = 0; i != parents.size(); ++i) {
        if (parents[i] == i)
            ++circlesCnt;
    }
    return circlesCnt;
}

#endif //ALGORITHMICCHALLENGES_547_FRIENDCIRCLES_H
