//https://leetcode.com/problems/3sum/
#ifndef ALGORITHMICCHALLENGES_15_3SUM_H
#define ALGORITHMICCHALLENGES_15_3SUM_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

template<typename ItT>
void moveToNextVal(ItT& it, const ItT& itE) {
    auto val = *it;
    do {
        ++it;
    } while (it != itE && *it == val);
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(begin(nums), end(nums));
    vector<vector<int>> triplets;
    for (auto it = begin(nums); it != end(nums);) {
        int target = -*it;
        for (auto left = it + 1; left != end(nums);) {
            int twoSum = target - *left;
            if (binary_search(left + 1, end(nums), twoSum))
                triplets.emplace_back(vector<int>{*it, *left, twoSum});
            moveToNextVal(left, end(nums));
        }
        moveToNextVal(it, end(nums));
    }
    return triplets;
}

#endif //ALGORITHMICCHALLENGES_15_3SUM_H
