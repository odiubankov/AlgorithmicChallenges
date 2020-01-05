//https://leetcode.com/problems/trapping-rain-water/
#ifndef ALGORITHMICCHALLENGES_42_TRAPPINGWATTER_H
#define ALGORITHMICCHALLENGES_42_TRAPPINGWATTER_H

#include <vector>
#include <limits>
#include <numeric>
#include <algorithm>

int calcCurrentTrap(std::vector<int>& trapVals) {
    int res = 0;
    if (trapVals.size() >= 3) {
        auto trapBottom = begin(trapVals) + 1;
        for (auto it = begin(trapVals) + 2; it != (end(trapVals) - 1); ++it) {
            if (*it < *trapBottom)
                trapBottom = it;
        }
        auto trapLeft = begin(trapVals);
        auto trapRight = end(trapVals) - 1;
        for (auto it = begin(trapVals) + 1; it != trapBottom; ++it) {
            if (*it >= *trapRight)
                trapLeft = it;
        }

        int trapWidth = std::distance(trapLeft, trapRight) - 1;
        int trapHeight = std::min(*trapLeft, *trapRight);
        res = std::max(0, trapWidth * trapHeight - std::accumulate(trapLeft + 1, trapRight, 0));
    }

    trapVals.clear();
    return res;
}

int trap(const std::vector<int>& height) {
    auto sortedHeight = height;
    std::sort(begin(sortedHeight),end(sortedHeight));
    int res = 0;
    int prevVal = std::numeric_limits<int>::min();
    std::vector<int> trapVals;
    for (auto h : height) {
        if (trapVals.empty()) {
            if (h < prevVal) {
                trapVals.push_back(prevVal);
                trapVals.push_back(h);
            }
        } else {
            trapVals.push_back(h);
            if (trapVals.front() <= trapVals.back() || (trapVals.back() == sortedHeight.back() && trapVals.size() > 2))
                res += calcCurrentTrap(trapVals);
        }

        sortedHeight.erase(std::lower_bound(begin(sortedHeight), end(sortedHeight), h));
        prevVal = h;
    }

    if (!trapVals.empty())
        res += calcCurrentTrap(trapVals);
    return res;
}

int trapSimple(const std::vector<int>& height) {
    if (height.size() < 3)
        return 0;
    int water = 0;
    auto leftIt = begin(height);
    auto rightIt = end(height) - 1;
    int maxLeft = 0, maxRight = 0;
    while (leftIt != rightIt) {
        if (*leftIt < *rightIt) {
            if (*leftIt < maxLeft) {
                water += (maxLeft - *leftIt);
            } else if (*leftIt > maxLeft) {
                maxLeft = *leftIt;
            }
            ++leftIt;
        } else { // *leftIt >= *rightIt
            if (*rightIt < maxRight) {
                water += (maxRight - *rightIt);
            } else if (*rightIt > maxRight) {
                maxRight = *rightIt;
            }
            --rightIt;
        }
    }

    return water;
}
#endif //ALGORITHMICCHALLENGES_42_TRAPPINGWATTER_H
