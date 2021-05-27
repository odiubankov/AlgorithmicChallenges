// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#ifndef ALGORITHMICCHALLENGES_703_KTHLARGESTELEMENTINSTREAM_H
#define ALGORITHMICCHALLENGES_703_KTHLARGESTELEMENTINSTREAM_H

#include <vector>
#include <queue>

class KthLargest {
    std::priority_queue<int, vector<int>, greater<int>> kSmall;
    int k_;

public:
    KthLargest(int k, const vector<int>& nums) : k_(k) {
        for (int i = 0; i < k && i < nums.size(); ++i)
            kSmall.push(nums[i]);

        for (int i = k; i < nums.size(); ++i) {
            kSmall.push(nums[i]);
            kSmall.pop();
        }
    }

    int add(int val) {
        kSmall.push(val);
        if (kSmall.size() > k_)
            kSmall.pop();
        return kSmall.top();
    }
};

#endif //ALGORITHMICCHALLENGES_703_KTHLARGESTELEMENTINSTREAM_H
