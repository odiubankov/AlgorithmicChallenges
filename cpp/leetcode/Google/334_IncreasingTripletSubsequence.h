//https://leetcode.com/problems/increasing-triplet-subsequence/
#ifndef ALGORITHMICCHALLENGES_334_INCREASINGTRIPLETSUBSEQUENCE_H
#define ALGORITHMICCHALLENGES_334_INCREASINGTRIPLETSUBSEQUENCE_H

#include <vector>
using namespace std;

const int SEQUENCE = 3;
bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < SEQUENCE)
        return false;
    vector<int> sequence(SEQUENCE - 1, numeric_limits<int>::max());
    for (auto num : nums) {
        bool allLess = true;
        for (auto& s : sequence) {
            if (s >= num) {
                allLess = false;
                s = num;
                break;
            }
        }
        if (allLess)
            return true;
    }
    return false;
}

#endif //ALGORITHMICCHALLENGES_334_INCREASINGTRIPLETSUBSEQUENCE_H
