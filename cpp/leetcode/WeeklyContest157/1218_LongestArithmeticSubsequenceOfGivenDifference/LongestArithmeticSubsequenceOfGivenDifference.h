//https://leetcode.com/contest/weekly-contest-157/problems/longest-arithmetic-subsequence-of-given-difference/
#ifndef ALGORITHMICCHALLENGES_LONGESTARITHMETICSUBSEQUENCEOFGIVENDIFFERENCE_H
#define ALGORITHMICCHALLENGES_LONGESTARITHMETICSUBSEQUENCEOFGIVENDIFFERENCE_H

#include <vector>
#include <unordered_map>
#include <algorithm>

class SolutionLongestSubsequence {
public:
    int longestSubsequence(const std::vector<int>& arr, int difference) {
        std::size_t maxLength = 0;
        std::unordered_map<int, std::size_t> valLengths;
        for (auto i : arr)
            maxLength = std::max(valLengths[i] = 1 + valLengths[i - difference], maxLength);

        return static_cast<int>(maxLength);
    }
};

#endif //ALGORITHMICCHALLENGES_LONGESTARITHMETICSUBSEQUENCEOFGIVENDIFFERENCE_H
