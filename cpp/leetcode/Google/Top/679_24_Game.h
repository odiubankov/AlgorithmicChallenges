//https://leetcode.com/problems/24-game/
#ifndef ALGORITHMICCHALLENGES_679_24_GAME_H
#define ALGORITHMICCHALLENGES_679_24_GAME_H

#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

vector<double> getCombinations(const vector<int>& nums) {
    if (nums.size() == 1)
        return {static_cast<double>(nums.back())};
    vector<double> combinations;
    for (size_t i = 0; i < nums.size(); ++i) {
        vector<int> other;
        other.reserve(nums.size() - 1);
        for (size_t j = 0; j < nums.size(); ++j) {
            if (i != j)
                other.push_back(nums[j]);
        }
        auto otherCombinations = getCombinations(other);
        for (auto val : otherCombinations) {
            combinations.push_back(nums[i] + val);
            combinations.push_back(nums[i] - val);
            combinations.push_back(nums[i] * val);
            combinations.push_back(nums[i] / val);
        }
    }

    if (nums.size() == 4) {
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                auto firstCombinations = getCombinations({nums[i], nums[j]});
                vector<int> secondNums;
                for (size_t k = 0; k < nums.size(); ++k) {
                    if (k != i && k != j)
                        secondNums.push_back(nums[k]);
                }
                auto secondCombinations = getCombinations(secondNums);
                for (auto firstVal : firstCombinations) {
                    for (auto secondVal : secondCombinations) {
                        combinations.push_back(firstVal * secondVal);
                        combinations.push_back(firstVal / secondVal);
                        combinations.push_back(firstVal + secondVal);
                        combinations.push_back(firstVal - secondVal);
                    }
                }
            }
        }
    }
    return combinations;
}

bool judgePoint24(const vector<int>& nums) {
    auto combinations = getCombinations(nums);
    return any_of(begin(combinations), end(combinations),
        [](double val){ return std::fabs(24.0-val) <= 0.00001;; });
}

#endif //ALGORITHMICCHALLENGES_679_24_GAME_H
