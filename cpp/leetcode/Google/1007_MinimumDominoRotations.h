//https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
#ifndef ALGORITHMICCHALLENGES_1007_MINIMUMDOMINOROTATIONS_H
#define ALGORITHMICCHALLENGES_1007_MINIMUMDOMINOROTATIONS_H

#include <vector>
#include <limits>

void getMinRotations(int& minRotations, int rotations) {
    if (rotations != -1 && rotations < minRotations)
        minRotations = rotations;
}

bool updateRotations(int val, int& valTop, int& valBottom, int top, int bottom, int other) {
    if (valTop != -1) {
        if (val != top && val != bottom) {
            if (other == -1)
                return false;
            valTop = -1;
            valBottom = -1;
        } else if (val == top && val != bottom) {
            ++valBottom;
        } else if (val != top && val == bottom) {
            ++valTop;
        }
    }
    return true;
}

int minDominoRotations(const std::vector<int>& A, const std::vector<int>& B) {
    if (A.empty())
        return 0;
    auto Ait = begin(A);
    auto Bit = begin(B);
    int val1 = *Ait;
    int val2 = *Bit;
    int val1Top = 0, val2Top = val2 != val1 ? 1 : 0, val1Bottom = val2 != val1 ? 1 : 0, val2Bottom = 0;
    ++Ait;
    ++Bit;
    for (;Ait != end(A); ++Ait, ++Bit) {
        if (!updateRotations(val1, val1Top, val1Bottom, *Ait, *Bit, val2Top) ||
            !updateRotations(val2, val2Top, val2Bottom, *Ait, *Bit, val1Top))
            return -1;
    }
    auto minRotations = std::numeric_limits<int>::max();
    getMinRotations(minRotations, val1Top);
    getMinRotations(minRotations, val1Bottom);
    getMinRotations(minRotations, val2Top);
    getMinRotations(minRotations, val2Bottom);
    return minRotations;
}

#endif //ALGORITHMICCHALLENGES_1007_MINIMUMDOMINOROTATIONS_H
