//https://leetcode.com/problems/split-array-into-consecutive-subsequences/
#ifndef ALGORITHMICCHALLENGES_659_SPLITARRAYINTOCONSECUTIVESUBSEQUENCES_H
#define ALGORITHMICCHALLENGES_659_SPLITARRAYINTOCONSECUTIVESUBSEQUENCES_H

#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool isPossible(const vector<int>& nums) {
    if (nums.size() < 3)
        return false;
    deque<pair<int, int>> subsequences;
    subsequences.emplace_back(nums.front(), 1);
    auto it = begin(nums) + 1;
    while (it != end(nums)) {
        if (*it == subsequences.back().first) {
            subsequences.emplace_front(*it, 1);
            ++it;
        } else if ((*it - subsequences.back().first) > 1) {
            if (any_of(begin(subsequences), end(subsequences), [](auto& ss) { return ss.second < 3; }))
                return false;
            subsequences.clear();
            subsequences.emplace_back(*it, 1);
            ++it;
        } else { //(*it - subsequences.back().back()) == 1
            auto ssIt = begin(subsequences);
            for (; ssIt != end(subsequences) && it != end(nums) && ((*it - ssIt->first) == 1); ++ssIt, ++it) {
                ssIt->first = *it;
                ++ssIt->second;
            }
            if (any_of(ssIt, end(subsequences), [](auto& ss) { return ss.second < 3; } ))
                return false;
            subsequences.erase(ssIt, end(subsequences));
        }
    }
    return all_of(begin(subsequences), end(subsequences), [](auto& ss) { return ss.second >= 3; });
}

#endif //ALGORITHMICCHALLENGES_659_SPLITARRAYINTOCONSECUTIVESUBSEQUENCES_H
