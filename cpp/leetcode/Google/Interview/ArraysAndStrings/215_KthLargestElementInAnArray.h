//https://leetcode.com/problems/kth-largest-element-in-an-array/
#ifndef ALGORITHMICCHALLENGES_215_KTHLARGESTELEMENTINANARRAY_H
#define ALGORITHMICCHALLENGES_215_KTHLARGESTELEMENTINANARRAY_H

#include <vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));
    return *(rbegin(nums) + k - 1);
}

#endif //ALGORITHMICCHALLENGES_215_KTHLARGESTELEMENTINANARRAY_H
