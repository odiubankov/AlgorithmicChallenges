//https://leetcode.com/problems/split-array-into-consecutive-subsequences/
#ifndef ALGORITHMICCHALLENGES_659_SPLITARRAYINTOCONSECUTIVESUBSEQUENCES_H
#define ALGORITHMICCHALLENGES_659_SPLITARRAYINTOCONSECUTIVESUBSEQUENCES_H

#include <vector>
#include <unordered_map>

using namespace std;

bool isPossible(const vector<int>& nums) {
    unordered_map<int, int> valsCnt, tails;
    for (auto num : nums)
        ++valsCnt[num];
    for (auto num : nums) {
        if (valsCnt[num] > 0) {
            if (tails[num] > 0) {
                --tails[num];
                ++tails[num + 1];
            } else if (valsCnt[num + 1] > 0 &&valsCnt[num + 2] > 0) {
                --valsCnt[num + 1];
                --valsCnt[num + 2];
                ++tails[num + 3];
            } else {
                return false;
            }
            --valsCnt[num];
        }
    }
    return true;
}

#endif //ALGORITHMICCHALLENGES_659_SPLITARRAYINTOCONSECUTIVESUBSEQUENCES_H
