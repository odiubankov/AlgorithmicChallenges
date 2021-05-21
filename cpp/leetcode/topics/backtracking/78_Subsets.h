// https://leetcode.com/problems/subsets/description/

#include <vector>
#include <unordered_map>

#ifndef ALGORITHMICCHALLENGES_78_SUBSETS_H
#define ALGORITHMICCHALLENGES_78_SUBSETS_H

using ItemsCntT = std::unordered_map<int, int>;
using ResultT = std::vector<int>;
using ResultsT = std::vector<ResultT>;

void getNextRes(ItemsCntT::iterator itemIt, ItemsCntT::iterator itemEnd, ResultT result, ResultsT& results) {
    if (itemIt == itemEnd) {
        results.push_back(result);
        return;
    }

    auto nextItem = itemIt;
    ++nextItem;
    getNextRes(nextItem, itemEnd, result, results);
    for (int i = 0; i != itemIt->second; ++i) {
        result.push_back(itemIt->first);
        getNextRes(nextItem, itemEnd, result, results);
    }
}

ResultsT subsets(const std::vector<int>& nums) {
    ItemsCntT itemsCnt;
    for (auto num : nums) {
        ++itemsCnt[num];
    }

    ResultsT results;
    ResultT result;
    getNextRes(begin(itemsCnt), end(itemsCnt), result, results);
    return results;
}

#endif //ALGORITHMICCHALLENGES_78_SUBSETS_H
