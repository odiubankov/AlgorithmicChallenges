//https://leetcode.com/problems/missing-ranges/
#ifndef ALGORITHMICCHALLENGES_163_MISSINGRANGES_H
#define ALGORITHMICCHALLENGES_163_MISSINGRANGES_H

#include <vector>
#include <string>
#include <sstream>
using namespace std;

string createRange(long low, long up) {
    stringstream ss;
    auto diff = up - low;
    if (diff > 0) {
        ss << low << "->" << up;
    } else if (diff == 0) {
        ss << low;
    }
    return ss.str();
}

vector<string> findMissingRanges(const vector<int>& nums, int lower, int upper) {
    vector<string> missingRanges;
    if (nums.empty()) {
        string range = createRange(lower, upper);
        if (!range.empty())
            missingRanges.push_back(move(range));
        return missingRanges;
    }
    string range = createRange(lower, static_cast<long>(nums.front()) - 1);
    if (!range.empty())
        missingRanges.push_back(move(range));
    auto numIt1 = begin(nums);
    auto numIt2 = numIt1 + 1;
    for (;numIt2 != end(nums); ++numIt1, ++numIt2) {
        range = createRange(static_cast<long>(*numIt1) + 1, static_cast<long>(*numIt2) - 1);
        if (!range.empty())
            missingRanges.push_back(move(range));
    }
    range = createRange(static_cast<long>(nums.back()) + 1, upper);
    if (!range.empty())
        missingRanges.push_back(move(range));
    return missingRanges;
}

#endif //ALGORITHMICCHALLENGES_163_MISSINGRANGES_H
