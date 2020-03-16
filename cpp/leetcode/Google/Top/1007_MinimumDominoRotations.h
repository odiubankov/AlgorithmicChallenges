//https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
#ifndef ALGORITHMICCHALLENGES_1007_MINIMUMDOMINOROTATIONS_H
#define ALGORITHMICCHALLENGES_1007_MINIMUMDOMINOROTATIONS_H

#include <vector>
#include <limits>

int getMinRotationsBottom(const std::vector<int>& top, const std::vector<int>& bottom) {
    if (top.empty())
        return 0;
    int minRotations = 0;
    auto val = top.front();
    for (auto topIt = begin(top), bottomIt = begin(bottom); topIt != end(top); ++topIt, ++bottomIt) {
        if (*bottomIt == val)
            continue;
        if (*topIt == val)
            ++minRotations;
        else
            return std::numeric_limits<int>::max();
    }
    return minRotations;
}

int getMinRotationsTop(const std::vector<int>& top, const std::vector<int>& bottom) {
    if (top.empty())
        return 0;
    int minRotations = 0;
    auto val = top.front();
    for (auto topIt = begin(top), bottomIt = begin(bottom); topIt != end(top); ++topIt, ++bottomIt) {
        if (*topIt == val)
            continue;
        if (*bottomIt == val)
            ++minRotations;
        else
            return std::numeric_limits<int>::max();
    }
    return minRotations;
}

int minDominoRotations(const std::vector<int>& A, const std::vector<int>& B) {
    auto minRotationsTop = std::min(getMinRotationsTop(A, B), getMinRotationsTop(B, A));
    auto minRotationsBottom = std::min(getMinRotationsBottom(A, B), getMinRotationsBottom(B, A));
    auto minRotations = std::min(minRotationsTop, minRotationsBottom);
    if (minRotations == std::numeric_limits<int>::max())
        return -1;
    return minRotations;
}

#endif //ALGORITHMICCHALLENGES_1007_MINIMUMDOMINOROTATIONS_H
