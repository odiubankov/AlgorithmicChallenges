//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#ifndef ALGORITHMICCHALLENGES_34_FINDFIRSTANDLASTPOSITIONOFELEMENTINSORTEDARRAY_H
#define ALGORITHMICCHALLENGES_34_FINDFIRSTANDLASTPOSITIONOFELEMENTINSORTEDARRAY_H

#include <vector>
#include <iterator>

using namespace std;

using VectorIteratorT = vector<int>::iterator;

VectorIteratorT lowerBound(VectorIteratorT itB, VectorIteratorT itE, int target) {
    auto l = itB;
    auto r = itE;
    auto targetIt = itE;
    while (l < r) {
        auto m = l + distance(l, r) / 2;
        if (*m < target) {
            l = m + 1;
        } else if (*m > target) {
            r = m;
        } else {
            targetIt = m;
            r = m;
        }
    }
    return targetIt;
}

VectorIteratorT upperBound(VectorIteratorT itB, VectorIteratorT itE, int target) {
    auto l = itB;
    auto r = itE;
    auto targetIt = itE;
    while (l < r) {
        auto m = l + distance(l, r) / 2;
        if (*m < target) {
            l = m + 1;
        } else if (*m > target) {
            r = m;
        } else {
            targetIt = m;
            l = m + 1;
        }
    }
    return targetIt;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    auto firstPos = lowerBound(begin(nums), end(nums), target);
    if (firstPos == end(nums))
        return {-1, -1};
    auto lastPos = upperBound(begin(nums), end(nums), target);
    return vector<int>{distance(begin(nums), firstPos), distance(begin(nums), lastPos)};
}

#endif //ALGORITHMICCHALLENGES_34_FINDFIRSTANDLASTPOSITIONOFELEMENTINSORTEDARRAY_H
