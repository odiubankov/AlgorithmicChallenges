//https://leetcode.com/problems/coin-change/
#ifndef ALGORITHMICCHALLENGES_322_COINCHANGE_H
#define ALGORITHMICCHALLENGES_322_COINCHANGE_H

#include <vector>
#include <limits>
using namespace std;

int coinChange(const vector<int>& coins, int amount) {
    if (amount == 0)
        return 0;
    vector<int> amountCoinsCnt(amount + 1, numeric_limits<int>::max());
    amountCoinsCnt[0] = 0;
    for (int i = 1; i != amountCoinsCnt.size(); ++i) {
        int minCoinsCnt = numeric_limits<int>::max();
        for (auto coin : coins) {
            if (i >= coin)
                minCoinsCnt = min(amountCoinsCnt[i - coin], minCoinsCnt);
        }
        if (minCoinsCnt != numeric_limits<int>::max())
            ++minCoinsCnt;
        amountCoinsCnt[i] = minCoinsCnt;
    }
    if (amountCoinsCnt.back() == numeric_limits<int>::max())
        return -1;
    return amountCoinsCnt.back();
}

#endif //ALGORITHMICCHALLENGES_322_COINCHANGE_H
