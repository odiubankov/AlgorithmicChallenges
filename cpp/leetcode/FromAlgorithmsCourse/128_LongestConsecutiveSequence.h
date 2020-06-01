//https://leetcode.com/problems/longest-consecutive-sequence/
#ifndef ALGORITHMICCHALLENGES_128_LONGESTCONSECUTIVESEQUENCE_H
#define ALGORITHMICCHALLENGES_128_LONGESTCONSECUTIVESEQUENCE_H

#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int> const& nums) {
    int maxLength = 0;
    unordered_set<int> numsSet;
    for (auto num : nums)
        numsSet.insert(num);

    for (auto num : nums) {
        if (numsSet.find(num - 1) == end(numsSet)) {
            int length = 1;
            auto sequenceNumber = num;
            while (numsSet.find(++sequenceNumber) != end(numsSet))
                ++length;
            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
}
#endif //ALGORITHMICCHALLENGES_128_LONGESTCONSECUTIVESEQUENCE_H
