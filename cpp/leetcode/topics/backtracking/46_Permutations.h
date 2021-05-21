// https://leetcode.com/problems/permutations/description/

#include <vector>
#include <unordered_map>

#ifndef ALGORITHMICCHALLENGES_46_PERMUTATIONS_H
#define ALGORITHMICCHALLENGES_46_PERMUTATIONS_H

using ItemsCntT = std::unordered_map<int, int>;
using ResultT = std::vector<int>;
using ResultsT = std::vector<ResultT>;

void getNextRes(ItemsCntT& itemsCnt, ResultT& result, ResultsT& results, int cnt) {
    if (cnt == result.size()){
        results.push_back(result);
        return;
    }

    for (auto& itemCnt : itemsCnt) {
        if (result.empty() || itemCnt.first != result.back()) {
            int originalItemCnt = itemCnt.second;
            for (int i = 1; i <= originalItemCnt; ++i) {
                for (int j = 0; j < i; ++j)
                    result.push_back(itemCnt.first);
                --itemCnt.second;
                getNextRes(itemsCnt, result, results, cnt);
                for (int j = 0; j < i; ++j)
                    result.pop_back();
            }

            itemCnt.second = originalItemCnt;
        }
    }
}

std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
    ItemsCntT itemsCnt;
    for (auto num : nums) {
        ++itemsCnt[num];
    }

    ResultsT results;
    ResultT result;
    getNextRes(itemsCnt, result, results, nums.size());
    return results;
}

#endif //ALGORITHMICCHALLENGES_46_PERMUTATIONS_H
