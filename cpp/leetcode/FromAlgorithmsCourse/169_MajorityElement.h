//https://leetcode.com/problems/majority-element/

#ifndef ALGORITHMICCHALLENGES_169_MAJORITYELEMENT_H
#define ALGORITHMICCHALLENGES_169_MAJORITYELEMENT_H

#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int majorityVal = 0;
    int cnt = 0;
    for (auto val : nums) {
        if (cnt == 0) {
            majorityVal = val;
            cnt = 1;
        } else if (val == majorityVal) {
            ++cnt;
        } else {
            --cnt;
        }
    }
    return majorityVal;
}

#endif //ALGORITHMICCHALLENGES_169_MAJORITYELEMENT_H
