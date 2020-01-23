//https://leetcode.com/problems/peak-index-in-a-mountain-array/
#ifndef ALGORITHMICCHALLENGES_852_PEAKINDEXMOUNTAINARRAY_H
#define ALGORITHMICCHALLENGES_852_PEAKINDEXMOUNTAINARRAY_H

#include <vector>
using namespace std;

int peakIndexInMountainArray(const vector<int>& A) {
    auto upIt = begin(A);
    auto downIt = end(A);
    while (distance(upIt, downIt) > 3) {
        auto oneThirdLength = distance(upIt, downIt) / 3;
        auto midIt1 = upIt + oneThirdLength;
        auto midIt2 = upIt + 2 * oneThirdLength;
        if (*midIt2 >= *midIt1 && *midIt2 >= *upIt) {
            upIt = midIt1;
        } else if (*midIt2 < *midIt1) {
            downIt = midIt2 + 1;
        } else if (*midIt1 < *upIt) {
            downIt = midIt1 + 1;
        }
    }
    return distance(begin(A), upIt) + 1;
}

#endif //ALGORITHMICCHALLENGES_852_PEAKINDEXMOUNTAINARRAY_H
