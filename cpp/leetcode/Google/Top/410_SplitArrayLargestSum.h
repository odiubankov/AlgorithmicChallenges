//https://leetcode.com/problems/split-array-largest-sum/
#ifndef ALGORITHMICCHALLENGES_410_SPLITARRAYLARGESTSUM_H
#define ALGORITHMICCHALLENGES_410_SPLITARRAYLARGESTSUM_H

#include <vector>
#include <numeric>
#include <unordered_map>
#include <limits>

using ValsT = std::vector<int>;
using CacheT = std::unordered_map<std::size_t, std::unordered_map<std::size_t, std::unordered_map<int, unsigned long long>>>;

unsigned long long splitArrayImpl(const ValsT& nums, std::size_t bIt, std::size_t eIt, unsigned long long sum, int m, CacheT& cache) {
    auto resIt = cache[bIt][eIt].find(m);
    if (resIt != end(cache[bIt][eIt]))
        return resIt->second;
    auto minMaxSum = std::numeric_limits<unsigned long long>::max();
    if (m == 1) {
        minMaxSum = sum;
    } else {
        unsigned long long leftSum = nums[bIt];
        for (auto midIt = bIt + 1; midIt != eIt; ++midIt) {
            if (leftSum >= minMaxSum)
                break;
            int rightSum = sum - leftSum;
            auto rightMinMaxSum = splitArrayImpl(nums, midIt, eIt, rightSum, m - 1, cache);
            auto maxSum = std::max(leftSum, rightMinMaxSum);
            if (maxSum < minMaxSum)
                minMaxSum = maxSum;
            leftSum += nums[midIt];
        }
    }

    cache[bIt][eIt][m] = minMaxSum;
    return minMaxSum;
}

int splitArray(const ValsT& nums, int m) {
    unsigned long long totalSum = 0;
    totalSum = std::accumulate(begin(nums), end(nums), totalSum);
    CacheT cache;
    return static_cast<int>(splitArrayImpl(nums, 0, nums.size(), totalSum, m, cache));
}

bool canSplitWithMaxSum(unsigned long long maxSum, const ValsT& nums, int parts) {
    int cnt = 1;
    unsigned long long sum = 0;
    for (int n : nums) {
        sum += n;
        if (sum > maxSum) {
            ++cnt;
            if (cnt > parts)
                return false;
            sum = n;
        }
    }
    return true;
}

int splitArrayBST(const ValsT& nums, int m) {
    unsigned long long sum = 0;
    int maxVal = std::numeric_limits<int>::min();
    for (int num : nums) {
        sum += num;
        if (num > maxVal)
            maxVal = num;
    }

    unsigned long long l = maxVal, r = sum;
    while (l <= r) {
        auto mid = (l + r) / 2;
        if (canSplitWithMaxSum(mid, nums, m))
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

#endif //ALGORITHMICCHALLENGES_410_SPLITARRAYLARGESTSUM_H
