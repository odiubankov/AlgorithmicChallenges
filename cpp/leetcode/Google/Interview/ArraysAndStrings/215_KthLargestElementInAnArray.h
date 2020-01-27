//https://leetcode.com/problems/kth-largest-element-in-an-array/
#ifndef ALGORITHMICCHALLENGES_215_KTHLARGESTELEMENTINANARRAY_H
#define ALGORITHMICCHALLENGES_215_KTHLARGESTELEMENTINANARRAY_H

#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));
    return *(rbegin(nums) + k - 1);
}

int findKthLargestHeap(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int> > topK;
    for (int i = 0; i != k; ++i)
        topK.push(nums[i]);
    for (int i = k; i != nums.size(); ++i) {
        topK.push(nums[i]);
        topK.pop();
    }
    return topK.top();
}

#endif //ALGORITHMICCHALLENGES_215_KTHLARGESTELEMENTINANARRAY_H
