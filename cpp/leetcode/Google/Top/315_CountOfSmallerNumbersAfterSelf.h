//https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#ifndef ALGORITHMICCHALLENGES_315_COUNTOFSMALLERNUMBERSAFTERSELF_H
#define ALGORITHMICCHALLENGES_315_COUNTOFSMALLERNUMBERSAFTERSELF_H

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> countSmaller(const vector<int>& nums) {
    if (nums.empty())
        return {};
    auto sorted = nums;
    sort(begin(sorted), end(sorted), greater<>());
    vector<int> smaller;
    smaller.reserve(nums.size());
    for (int num : nums) {
        auto it = upper_bound(begin(sorted), end(sorted), num, greater<>());
        smaller.push_back(distance(it, end(sorted)));
        sorted.erase(it - 1);
    }
    return smaller;
}

struct Item{
    int val_ = 0;
    int smaller_ = 0;
    int index_ = 0;
    Item(int val, int index) : val_{val}, index_{index} {}
};

using ItemsT = vector<Item>;
using ItT = ItemsT::iterator;

void mergeSort(const ItT& itB, const ItT& itE) {
    auto cnt = distance(itB, itE);
    if (cnt <= 1)
        return;
    int half = cnt / 2;
    auto firstB = itB, firstE = itB + half, secondB = firstE, secondE = itE;
    mergeSort(firstB, firstE);
    mergeSort(secondB, secondE);
    ItemsT res;
    res.reserve(cnt);
    int smaller = 0;
    while (firstB != firstE || secondB != secondE) {
        if (firstB == firstE) {
            res.push_back(*secondB++);
        } else if (secondB == secondE || firstB->val_ <= secondB->val_) {
            res.push_back(*firstB++);
            res.back().smaller_ += smaller;
        } else {
            ++smaller;
            res.push_back(*secondB++);
        }
    }
    copy(begin(res), end(res), itB);
}

vector<int> countSmallerMergeSort(const vector<int>& nums) {
    vector<Item> items;
    items.reserve(nums.size());
    for (int i = 0; i < nums.size(); ++i)
        items.emplace_back(nums[i], i);
    mergeSort(begin(items), end(items));
    vector<int> smaller(nums.size(), 0);
    for (const auto& item : items)
        smaller[item.index_] = item.smaller_;
    return smaller;
}

#endif //ALGORITHMICCHALLENGES_315_COUNTOFSMALLERNUMBERSAFTERSELF_H
