//https://leetcode.com/problems/longest-consecutive-sequence/
#ifndef ALGORITHMICCHALLENGES_128_LONGESTCONSECUTIVESEQUENCE_H
#define ALGORITHMICCHALLENGES_128_LONGESTCONSECUTIVESEQUENCE_H

#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using NumsSetT = unordered_set<int>;
using FinishAtSequenceT = unordered_map<int, int>;
int getSequenceLength(int val, FinishAtSequenceT& finishAtSequence, const NumsSetT& numSet) {
    auto prevIt = numSet.find(val - 1);
    if (prevIt == end(numSet))
        return 1;
    auto prevLengthIt = finishAtSequence.find(val - 1);
    if (prevLengthIt == end(finishAtSequence)) {
        finishAtSequence[val - 1] = getSequenceLength(val - 1, finishAtSequence, numSet);
    }
    finishAtSequence[val] = finishAtSequence[val - 1] + 1;
    return finishAtSequence[val];
}

int longestConsecutive(vector<int> const& nums) {
    int maxLength = 0;
    NumsSetT numsSet{begin(nums), end(nums)};
    FinishAtSequenceT finishAtSequence;
    for (auto num : nums) {
        maxLength = std::max(maxLength, getSequenceLength(num, finishAtSequence, numsSet));
    }

    return maxLength;
}
#endif //ALGORITHMICCHALLENGES_128_LONGESTCONSECUTIVESEQUENCE_H
