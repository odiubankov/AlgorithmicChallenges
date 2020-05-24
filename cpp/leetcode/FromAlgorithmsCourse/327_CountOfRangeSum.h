//https://leetcode.com/problems/count-of-range-sum/
#ifndef ALGORITHMICCHALLENGES_327_COUNTOFRANGESUM_H
#define ALGORITHMICCHALLENGES_327_COUNTOFRANGESUM_H

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// sumEndingAtI = sumOfAll - sumEndingAtJ

int countRangeSum(vector<int> const& nums, int lower, int upper) {
    int rangeSumCnt = 0;
    multiset<long long> prefixSums{0};
    long long sum = 0;
    for (auto num : nums) {
        sum += num;
        auto sumsBegin = prefixSums.lower_bound(sum - upper);
        auto sumsEnd = prefixSums.upper_bound(sum - lower);
        rangeSumCnt += distance(sumsBegin, sumsEnd);
        prefixSums.insert(sum);
    }
    return rangeSumCnt;
}

#endif //ALGORITHMICCHALLENGES_327_COUNTOFRANGESUM_H
