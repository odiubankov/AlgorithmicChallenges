//https://leetcode.com/problems/next-permutation/
#ifndef ALGORITHMICCHALLENGES_31_NEXTPERMUTATION_H
#define ALGORITHMICCHALLENGES_31_NEXTPERMUTATION_H

#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    if (!next_permutation(begin(nums), end(nums)))
        sort(begin(nums), end(nums));
}

#endif //ALGORITHMICCHALLENGES_31_NEXTPERMUTATION_H
