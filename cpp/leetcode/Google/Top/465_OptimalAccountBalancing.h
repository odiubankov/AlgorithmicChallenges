//https://leetcode.com/problems/optimal-account-balancing/
#ifndef ALGORITHMICCHALLENGES_465_OPTIMALACCOUNTBALANCING_H
#define ALGORITHMICCHALLENGES_465_OPTIMALACCOUNTBALANCING_H

#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

using NonZeroBalancesT = multiset<int>;
using BalanceItT = NonZeroBalancesT::const_iterator;
using ZeroBalancesT = vector<BalanceItT>;

bool findCompensatingBalances(const BalanceItT& balanceBeginIt, const BalanceItT& balanceEndIt, ZeroBalancesT& zeroedBalances, int balancesCnt, int val) {
    if (balancesCnt == 1) {
        auto numIt = lower_bound(balanceBeginIt, balanceEndIt, val);
        if (numIt != balanceEndIt && *numIt == val) {
            zeroedBalances.push_back(numIt);
            return true;
        }
        return false;
    }

    for (auto deptIt = balanceBeginIt; deptIt != balanceEndIt; ++deptIt) {
        int remainingVal = val - *deptIt;
        auto nextIt = deptIt;
        ++nextIt;
        if (findCompensatingBalances(nextIt, balanceEndIt, zeroedBalances, balancesCnt - 1, remainingVal)) {
            zeroedBalances.push_back(deptIt);
            return true;
        }
    }

    return false;
}

int minTransfers(const vector<vector<int>>& transactions) {
    unordered_map<int, int> peopleBalances;
    for (auto& t : transactions) {
        peopleBalances[t[0]] -= t[2];
        peopleBalances[t[1]] += t[2];
    }

    multiset<int> nonZeroBalances;
    for (const auto& d : peopleBalances) {
        if (d.second != 0)
            nonZeroBalances.insert(d.second);
    }

    int totalTransfersCnt = 0;
    int balancesCnt = 2;
    while (!nonZeroBalances.empty()) {
        ZeroBalancesT zeroedBalances;
        while (!nonZeroBalances.empty() && findCompensatingBalances(begin(nonZeroBalances), end(nonZeroBalances), zeroedBalances, balancesCnt, 0)) {
            totalTransfersCnt += (balancesCnt - 1);
            for (auto it : zeroedBalances)
                nonZeroBalances.erase(it);
            zeroedBalances.clear();
        }
        ++balancesCnt;
    }
    return totalTransfersCnt;
}

#endif //ALGORITHMICCHALLENGES_465_OPTIMALACCOUNTBALANCING_H
