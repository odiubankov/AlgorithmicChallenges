//https://leetcode.com/problems/sort-colors/
#ifndef ALGORITHMICCHALLENGES_75_SORTCOLORS_H
#define ALGORITHMICCHALLENGES_75_SORTCOLORS_H

#include <vector>

using namespace std;
//red 0, white 1, blue 2
void sortColors(vector<int>& nums) {
    if (nums.empty())
        return;
    size_t redPos = 0, bluePos = nums.size() - 1;
    for (size_t i = 0; i != (bluePos + 1);) {
        if (nums[i] == 0) {
            std::swap(nums[redPos], nums[i]);
            ++redPos;
            ++i;
        } else if (nums[i] == 2) {
            std::swap(nums[bluePos], nums[i]);
            --bluePos;
        } else {
            ++i;
        }
    }
}

#endif //ALGORITHMICCHALLENGES_75_SORTCOLORS_H
