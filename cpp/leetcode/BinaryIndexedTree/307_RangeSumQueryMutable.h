//https://leetcode.com/problems/range-sum-query-mutable/
#ifndef ALGORITHMICCHALLENGES_307_RANGESUMQUERYMUTABLE_H
#define ALGORITHMICCHALLENGES_307_RANGESUMQUERYMUTABLE_H

#include <vector>
using namespace std;

class NumArray {
    vector<int> nums_;
    vector<int> prefixSums_;//Fenwick Tre

    void updateImpl(int index, int diff) {
        for (int i = index + 1; i < prefixSums_.size(); i += (i & (-i)))
            prefixSums_[i] += diff;
    }

    int sumUntil(int index) {
        int sumUntilIndex = 0;
        for (int i = index + 1; i > 0; i -= (i & (-i)))
            sumUntilIndex += prefixSums_[i];
        return sumUntilIndex;
    }

public:
    NumArray(vector<int> nums)
        : nums_{move(nums)}
        , prefixSums_(nums_.size() + 1, 0) {
        for (int i = 0; i < nums_.size(); ++i)
            updateImpl(i, nums_[i]);
    }

    void update(int index, int val) {
        updateImpl(index, val - nums_[index]);
        nums_[index] = val;
    }

    int sumRange(int i, int j) {
        return sumUntil(j) - sumUntil(i - 1);
    }
};

#endif //ALGORITHMICCHALLENGES_307_RANGESUMQUERYMUTABLE_H
