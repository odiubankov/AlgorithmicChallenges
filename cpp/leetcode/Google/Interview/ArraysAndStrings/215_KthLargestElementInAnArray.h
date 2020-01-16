//https://leetcode.com/problems/kth-largest-element-in-an-array/
#ifndef ALGORITHMICCHALLENGES_215_KTHLARGESTELEMENTINANARRAY_H
#define ALGORITHMICCHALLENGES_215_KTHLARGESTELEMENTINANARRAY_H

#include <vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));
    return *(rbegin(nums) + k - 1);
}

int findKthLargestHeap(vector<int>& nums, int k) {
    less<int> comp;
    make_heap(begin(nums), end(nums), comp);
    for (int i = 0; i < k - 1; ++i) {
        pop_heap(begin(nums), end(nums), comp);
        nums.pop_back();
    }
    return nums.front();
}

#endif //ALGORITHMICCHALLENGES_215_KTHLARGESTELEMENTINANARRAY_H
