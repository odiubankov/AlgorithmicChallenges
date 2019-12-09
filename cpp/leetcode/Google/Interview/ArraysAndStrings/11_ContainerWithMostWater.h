//https://leetcode.com/problems/container-with-most-water/
#ifndef ALGORITHMICCHALLENGES_11_CONTAINERWITHMOSTWATER_H
#define ALGORITHMICCHALLENGES_11_CONTAINERWITHMOSTWATER_H

#include <vector>
using namespace std;

template<typename ItT>
void moveLeft(ItT& leftIt, const ItT& rightIt) {
    auto leftVal = *leftIt;
    do {
        ++leftIt;
    } while (leftIt != rightIt && *leftIt < leftVal);
}

template<typename ItT>
void moveRight(ItT& rightIt, const ItT& leftIt) {
    auto rightVal = *rightIt;
    do {
        --rightIt;
    } while (leftIt != rightIt && *rightIt < rightVal);
}

int maxArea(const vector<int>& height) {
    if (height.size() < 2)
        return 0;
    auto leftIt = begin(height);
    auto rightIt = end(height) - 1;
    int maxArea = 0;
    while (leftIt != rightIt) {
        int area = distance(leftIt, rightIt) * min(*leftIt, *rightIt);
        maxArea = max(area, maxArea);
        if (*leftIt < *rightIt)
            moveLeft(leftIt, rightIt);
        else
            moveRight(rightIt, leftIt);
    }
    return maxArea;
}

#endif //ALGORITHMICCHALLENGES_11_CONTAINERWITHMOSTWATER_H
