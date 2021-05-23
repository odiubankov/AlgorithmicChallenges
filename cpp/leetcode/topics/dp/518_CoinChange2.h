// https://leetcode.com/problems/coin-change-2/

#ifndef ALGORITHMICCHALLENGES_518_COINCHANGE2_H
#define ALGORITHMICCHALLENGES_518_COINCHANGE2_H

#include <unordered_map>
#include <algorithm>
#include <vector>

using CacheT = std::unordered_map<int, std::unordered_map<int, int>>;
using CoinsT = vector<int>;
using CoinsItT = CoinsT::iterator;

int changeImpl(int amount, CoinsItT coinIt, CoinsItT coinItEnd, CacheT& cache) {
    if (coinIt == coinItEnd)
        return 0;

    if (*coinIt > amount)
        return 0;

    auto cacheIt = cache.find(amount);
    if (cacheIt != end(cache)) {
        auto cache2It = cacheIt->second.find(*coinIt);
        if (cache2It != end(cacheIt->second))
            return cache2It->second;
    }

    int res = 0;
    for (int i = 0;; ++i) {
        int rest = amount - i * *coinIt;
        if (rest == 0) {
            ++res;
            break;
        }

        if (rest < 0) {
            break;
        }

        res += changeImpl(rest, coinIt + 1, coinItEnd, cache);
    }

    cache[amount][*coinIt] = res;
    return res;
}

int change(int amount, vector<int>& coins) {
    if (amount == 0)
        return 1;
    std::sort(begin(coins), end(coins));
    CacheT cache;
    return changeImpl(amount, begin(coins), end(coins), cache);
}

#endif //ALGORITHMICCHALLENGES_518_COINCHANGE2_H
