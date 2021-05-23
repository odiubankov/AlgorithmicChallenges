// https://leetcode.com/problems/search-a-2d-matrix-ii/
#ifndef ALGORITHMICCHALLENGES_240_SEARCHA2DMATRIXII_H
#define ALGORITHMICCHALLENGES_240_SEARCHA2DMATRIXII_H

#include <vector>

struct Rect {
    int i = 0;
    int j = 0;
    int w = 0;
    int h = 0;
};

bool searchRectangleInMatrix(const std::vector<std::vector<int>>& matrix, int target, Rect rect) {
    if (rect.w <= 0 || rect.h <= 0)
        return false;

    int midW = rect.j + rect.w / 2;
    int midH = rect.i + rect.h / 2;
    int midVal = matrix[midH][midW];
    if (midVal == target)
        return true;

    if (rect.w == 1 && rect.h == 1)
        return false;

    if (midVal > target)
        return searchRectangleInMatrix(matrix, target, Rect{rect.i, rect.j, midW - rect.j, rect.h}) ||
               searchRectangleInMatrix(matrix, target, Rect{rect.i, midW, rect.j + rect.w - midW, midH - rect.i});
    else
        return searchRectangleInMatrix(matrix, target, Rect{rect.i, midW + 1, rect.j + rect.w - midW - 1, rect.h}) ||
               searchRectangleInMatrix(matrix, target, Rect{midH + 1, rect.j, midW - rect.j + 1, rect.i + rect.h - midH - 1});
}

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix.front().empty())
        return false;
    return searchRectangleInMatrix(matrix, target, Rect{0, 0, static_cast<int>(matrix.front().size()), static_cast<int>(matrix.size())});
}

#endif //ALGORITHMICCHALLENGES_240_SEARCHA2DMATRIXII_H
