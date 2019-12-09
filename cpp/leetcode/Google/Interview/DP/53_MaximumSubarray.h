//https://leetcode.com/problems/maximum-subarray/
#ifndef ALGORITHMICCHALLENGES_53_MAXIMUMSUBARRAY_H
#define ALGORITHMICCHALLENGES_53_MAXIMUMSUBARRAY_H

#include <vector>
#include <limits>
using namespace std;

int maxSubArray(const vector<int>& nums) {
    int maxSum = numeric_limits<int>::min();
    auto numIt = begin(nums);
    auto sum = *numIt;
    ++numIt;
    for (; numIt != end(nums); ++numIt) {
        if (*numIt < 0)
            maxSum = max(maxSum, sum);

        if (sum < 0) {
            sum = *numIt;
        } else {
            sum += *numIt;
            if (sum < 0)
                sum = *numIt;
        }
    }
    maxSum = max(maxSum, sum);
    return maxSum;
}

#endif //ALGORITHMICCHALLENGES_53_MAXIMUMSUBARRAY_H
