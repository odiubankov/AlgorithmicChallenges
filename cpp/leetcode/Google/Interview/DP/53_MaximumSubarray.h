//https://leetcode.com/problems/maximum-subarray/
#ifndef ALGORITHMICCHALLENGES_53_MAXIMUMSUBARRAY_H
#define ALGORITHMICCHALLENGES_53_MAXIMUMSUBARRAY_H

#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int> const& nums) {
    int maxSum = *max_element(begin(nums), end(nums));
    int sum = 0;
    for (auto n : nums) {
        sum += n;
        maxSum = max(maxSum, sum);
        sum = max(sum, 0);
    }
    return maxSum;
}

#endif //ALGORITHMICCHALLENGES_53_MAXIMUMSUBARRAY_H
