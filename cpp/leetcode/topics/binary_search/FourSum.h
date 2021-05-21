/**
* https://leetcode.com/problems/4sum/#/description
*/

#ifndef LEETCODESOLUTIONS_FOURSUM_H
#define LEETCODESOLUTIONS_FOURSUM_H

#include <vector>
#include <set>
#include <algorithm>

using NumsT = std::vector<int>;
using NumsIt = NumsT::iterator;

void nSumImpl(NumsIt const& beginIt, NumsIt const& endIt, std::set<NumsT>& res, int n, int target, NumsT& numsAttempt) {
    if (n == 1) {
        if (std::binary_search(beginIt, endIt, target)) {
            numsAttempt.push_back(target);
            res.insert(numsAttempt);
            numsAttempt.pop_back();
        }
    } else {
        for (auto it = beginIt;
             it != endIt;
             ++it) {
            numsAttempt.push_back(*it);
            nSumImpl(it + 1, endIt, res, n - 1, target - *it, numsAttempt);
            numsAttempt.pop_back();
        }
    }
}

std::vector<NumsT> fourSum(NumsT& nums, int target) {
    std::sort(begin(nums), end(nums));
    std::set<NumsT> res;
    NumsT numsAttempt;
    nSumImpl(begin(nums), end(nums), res, 4, target, numsAttempt);
    return {begin(res), end(res)};
}

#endif //LEETCODESOLUTIONS_FOURSUM_H
