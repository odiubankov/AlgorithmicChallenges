// https://leetcode.com/problems/search-in-rotated-sorted-array/

#ifndef ALGORITHMICCHALLENGES_33_SEARCHINROTATEDSORTEDARRAY_H
#define ALGORITHMICCHALLENGES_33_SEARCHINROTATEDSORTEDARRAY_H

#include <vector>
#include <algorithm>

int getMaxElementIndex(const std::vector<int>& nums) {
    auto beginIt = begin(nums);
    auto endIt = end(nums);
    while (beginIt < endIt) {
        auto midIt = beginIt + distance(beginIt, endIt) / 2;
        if (*midIt >= *beginIt)
            beginIt = midIt;
        else
            endIt = midIt;
        if (distance(beginIt, endIt) == 1) {
            break;
        }
    }
    return distance(begin(nums), beginIt);
}

int search(const std::vector<int>& nums, int target) {
    int maxElement = getMaxElementIndex(nums);
    auto rangeE = begin(nums) + maxElement + 1;
    auto elIt = std::lower_bound(begin(nums), rangeE, target);
    if (elIt != rangeE && *elIt == target)
        return distance(begin(nums), elIt);
    elIt = std::lower_bound(rangeE, end(nums), target);
    if (elIt != end(nums) && *elIt == target)
        return distance(begin(nums), elIt);
    return -1;
}

#endif //ALGORITHMICCHALLENGES_33_SEARCHINROTATEDSORTEDARRAY_H
