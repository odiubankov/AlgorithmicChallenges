//https://leetcode.com/problems/jump-game/
#ifndef ALGORITHMICCHALLENGES_55_JUMPGAME_H
#define ALGORITHMICCHALLENGES_55_JUMPGAME_H

#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    if (nums.size() <= 1)
        return true;
    int falseCnt = 0;
    for (auto i = nums.size() - 2;; --i) {
        bool res = nums[i] >falseCnt;
        falseCnt = res ? 0 : falseCnt + 1;
        if (i == 0)
            return res;
    }
}

#endif //ALGORITHMICCHALLENGES_55_JUMPGAME_H
