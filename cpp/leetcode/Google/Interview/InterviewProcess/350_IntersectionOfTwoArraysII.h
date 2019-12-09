//https://leetcode.com/problems/intersection-of-two-arrays-ii/
#ifndef ALGORITHMICCHALLENGES_350_INTERSECTIONOFTWOARRAYSII_H
#define ALGORITHMICCHALLENGES_350_INTERSECTIONOFTWOARRAYSII_H

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersect(const vector<int>& nums1, const vector<int>& nums2) {
    unordered_map<int, int> smallerCnt;
    for (auto var : nums1)
        ++smallerCnt[var];
    vector<int> res;
    for (auto var : nums2) {
        if (--smallerCnt[var] >= 0)
            res.push_back(var);
    }
    return res;
}

#endif //ALGORITHMICCHALLENGES_350_INTERSECTIONOFTWOARRAYSII_H
