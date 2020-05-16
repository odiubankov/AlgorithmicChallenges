//https://leetcode.com/problems/majority-element-ii/

#ifndef ALGORITHMICCHALLENGES_229_MAJORITYELEMENTII_H
#define ALGORITHMICCHALLENGES_229_MAJORITYELEMENTII_H

#include <vector>
#include <array>
#include <unordered_set>

using namespace std;

constexpr auto MAJORITY_COEFFICIENT = 3;

vector<int> majorityElement(const vector<int>& nums) {
    if (nums.empty())
        return {};
    array<int, MAJORITY_COEFFICIENT - 1> slots{0, 1}, cnts{};
    for (auto num : nums) {
        bool found = false;
        for (size_t i = 0; i != slots.size() && !found; ++i) {
            if (slots[i] == num) {
                ++cnts[i];
                found = true;
            }
        }
        for (size_t i = 0; i != cnts.size() && !found; ++i) {
            if (cnts[i] == 0) {
                cnts[i] = 1;
                slots[i] = num;
                found = true;
            }
        }
        if (!found) {
            for (auto& cnt : cnts) {
                --cnt;
            }
        }
    }
    vector<int> res;
    for (auto val : slots) {
        auto cnt = count(begin(nums), end(nums), val);
        if (cnt > nums.size() / MAJORITY_COEFFICIENT) {
            res.push_back(val);
        }
    }
    return res;
}

#endif //ALGORITHMICCHALLENGES_229_MAJORITYELEMENTII_H
