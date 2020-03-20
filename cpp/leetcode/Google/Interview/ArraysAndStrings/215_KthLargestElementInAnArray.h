//https://leetcode.com/problems/kth-largest-element-in-an-array/
#ifndef ALGORITHMICCHALLENGES_215_KTHLARGESTELEMENTINANARRAY_H
#define ALGORITHMICCHALLENGES_215_KTHLARGESTELEMENTINANARRAY_H

#include <vector>
#include <queue>
#include <random>
#include <algorithm>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    std::sort(begin(nums), end(nums));
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

int findKthLargestQuickSelect(vector<int>& nums, int k) {
    k = nums.size() - k;
    size_t left = 0, right = nums.size() - 1;
    std::random_device randomDevice;
    std::mt19937 randomEngine(randomDevice());
    while (left != right) {
        std::uniform_int_distribution<size_t> distribution(left, right);
        auto pivotIndex = distribution(randomEngine);
        auto pivot = nums[pivotIndex];
        swap(nums[right], nums[pivotIndex]);
        auto storeIndex = left;
        for (size_t i = left; i <= right; ++i) {
            if (nums[i] < pivot) {
                swap(nums[storeIndex], nums[i]);
                ++storeIndex;
            }
        }
        swap(nums[right], nums[storeIndex]);
        if (storeIndex < k)
            left = storeIndex + 1;
        else if (storeIndex > k)
            right = storeIndex - 1;
        else
            return nums[storeIndex];
    }
    return nums[left];
}

#endif //ALGORITHMICCHALLENGES_215_KTHLARGESTELEMENTINANARRAY_H
