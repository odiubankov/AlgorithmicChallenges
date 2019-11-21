//https://leetcode.com/problems/two-sum/
#ifndef ALGORITHMICCHALLENGES_1_TWOSUM_H
#define ALGORITHMICCHALLENGES_1_TWOSUM_H

#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> valuePositions;
    valuePositions.emplace(nums.front(), 0);
    for (std::size_t i = 1; i < nums.size(); ++i) {
        auto it = valuePositions.find(target - nums[i]);
        if (it != end(valuePositions))
            return { it->second, static_cast<int>(i)};
        valuePositions.emplace(nums[i], i);
    }

    return {};
}

#endif //ALGORITHMICCHALLENGES_1_TWOSUM_H
