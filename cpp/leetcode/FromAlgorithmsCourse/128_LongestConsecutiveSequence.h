//https://leetcode.com/problems/longest-consecutive-sequence/
#ifndef ALGORITHMICCHALLENGES_128_LONGESTCONSECUTIVESEQUENCE_H
#define ALGORITHMICCHALLENGES_128_LONGESTCONSECUTIVESEQUENCE_H

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int> const& nums) {
    if (nums.size() < 2)
        return nums.size();

    unordered_set<int> vals{begin(nums), end(nums)};
    unordered_map<int, int> lengthEndings;
    for (auto num : nums) {
        if (lengthEndings.find(num) != end(lengthEndings))
            continue;
        int sequenceBegin = num;
        for (int i = num - 1; vals.find(i) != end(vals); --i) {
            sequenceBegin = i;
            if (lengthEndings.find(i) != end(lengthEndings)) {
                break;
            }
        }

        for (int i = sequenceBegin; i <= num; ++i) {
            lengthEndings[i] = lengthEndings[i - 1] + 1;
        }
    }

    int maxLength = 1;
    for (auto l : lengthEndings) {
        maxLength = std::max(maxLength, l.second);
    }

    return maxLength;
}
#endif //ALGORITHMICCHALLENGES_128_LONGESTCONSECUTIVESEQUENCE_H
