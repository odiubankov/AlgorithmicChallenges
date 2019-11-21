//https://leetcode.com/problems/optimal-account-balancing/
#ifndef ALGORITHMICCHALLENGES_465_OPTIMALACCOUNTBALANCING_H
#define ALGORITHMICCHALLENGES_465_OPTIMALACCOUNTBALANCING_H

#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

using SortedDeptsT = multiset<int>;
using DeptItT = SortedDeptsT::const_iterator;
using UsedItersT = vector<DeptItT>;

bool nSum(const DeptItT& deptBeginIt, const DeptItT& deptEndIt, UsedItersT& usedIters, int n, int val) {
    if (n == 1) {
        auto numIt = lower_bound(deptBeginIt, deptEndIt, val);
        if (numIt != deptEndIt && *numIt == val) {
            usedIters.push_back(numIt);
            return true;
        }
        return false;
    }

    for (auto deptIt = deptBeginIt; deptIt != deptEndIt; ++deptIt) {
        int remainingVal = val - *deptIt;
        auto nextIt = deptIt;
        ++nextIt;
        if (nSum(nextIt, deptEndIt,usedIters,n - 1, remainingVal)) {
            usedIters.push_back(deptIt);
            return true;
        }
    }

    return false;
}

int minTransfers(const vector<vector<int>>& transactions) {
    unordered_map<int, int> depts;
    for (auto& t : transactions) {
        depts[t[0]] -= t[2];
        depts[t[1]] += t[2];
    }

    multiset<int> sortedDepts;
    for (const auto& d : depts) {
        if (d.second != 0)
            sortedDepts.insert(d.second);
    }

    int transfers = 0;
    int n = 2;
    while (!sortedDepts.empty()) {
        UsedItersT usedIters;
        while (!sortedDepts.empty() && nSum(begin(sortedDepts), end(sortedDepts), usedIters, n, 0)) {
            transfers += (n - 1);
            for (auto it : usedIters)
                sortedDepts.erase(it);
            usedIters.clear();
        }
        ++n;
    }
    return transfers;
}

#endif //ALGORITHMICCHALLENGES_465_OPTIMALACCOUNTBALANCING_H
