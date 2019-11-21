//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
#ifndef ALGORITHMICCHALLENGES_801_MINIMUMSWAPSTOMAKESEQUENCESINCREASING_H
#define ALGORITHMICCHALLENGES_801_MINIMUMSWAPSTOMAKESEQUENCESINCREASING_H

#include <vector>
using namespace std;

vector<bool> getSwaps(const vector<int>& A, const vector<int>& B, size_t j) {
    vector<bool> lefts{true};
    for (size_t i = j; i < A.size(); ++i) {
        if (A[i] > A[i - 1] && A[i] >B[i - 1] && B[i] > B[i - 1] && B[i] > A[i - 1])
            break;
        if (lefts.back())
            lefts.push_back(!(A[i] <= A[i - 1] || B[i] <= B[i - 1]));
        else
            lefts.push_back(!(A[i] <= B[i - 1] || B[i] <= A[i - 1]));
    }
    return lefts;
}

int minSwap(const vector<int>& A, const vector<int>& B) {
    int minSwaps = 0;
    for (size_t i = 1; i < A.size();) {
        auto swaps = getSwaps(A, B, i);
        if (swaps.size() == 1) {
            ++i;
        } else {
            auto leftsCnt = count(begin(swaps), end(swaps), true);
            minSwaps += min<int>(leftsCnt, swaps.size() - leftsCnt);
            i += swaps.size();
        }
    }
    return minSwaps;
}

#endif //ALGORITHMICCHALLENGES_801_MINIMUMSWAPSTOMAKESEQUENCESINCREASING_H
