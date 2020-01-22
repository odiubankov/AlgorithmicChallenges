//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
#ifndef ALGORITHMICCHALLENGES_801_MINIMUMSWAPSTOMAKESEQUENCESINCREASING_H
#define ALGORITHMICCHALLENGES_801_MINIMUMSWAPSTOMAKESEQUENCESINCREASING_H

#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

// [3,3,8,9,10]
// [1,7,4,6,8]

int minSwap(const vector<int>& A, const vector<int>& B) {
    if (A.size() < 2)
        return 0;
    int prevSwappedCnt = 1;
    int prevOriginalCnt = 0;
    auto aPrevIt = begin(A);
    auto bPrevIt = begin(B);
    for (auto aIt = aPrevIt + 1, bIt = bPrevIt + 1; aIt != end(A); ++aIt, ++bIt, ++aPrevIt, ++bPrevIt) {
        int swappedCnt = numeric_limits<int>::max();
        int originalCnt = numeric_limits<int>::max();
        if (*aIt > *aPrevIt && *bIt > *bPrevIt) {
            swappedCnt = prevSwappedCnt + 1;
            originalCnt = prevOriginalCnt;
        }
        if (*aIt > *bPrevIt && *bIt > *aPrevIt) {
            swappedCnt = min(swappedCnt, prevOriginalCnt + 1);
            originalCnt = min(originalCnt, prevSwappedCnt);
        }
        prevSwappedCnt = swappedCnt;
        prevOriginalCnt = originalCnt;
    }
    return min(prevSwappedCnt, prevOriginalCnt);
}

#endif //ALGORITHMICCHALLENGES_801_MINIMUMSWAPSTOMAKESEQUENCESINCREASING_H
