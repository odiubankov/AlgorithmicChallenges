#pragma once
#include <vector>
#include <map>

namespace hackerrank {

  using CoinsT = std::vector<long long>;
  using CacheT = std::map<std::pair<long long, CoinsT::const_iterator>, long long>;

long long getWaysImpl(
    long long n,
    CoinsT::const_iterator coinIt,
    const CoinsT::const_iterator& coinItEnd,
    CacheT& cache) {
    if (coinIt == coinItEnd)
        return 0;

    auto cacheKey = std::make_pair(n, coinIt);
    auto cacheIt = cache.find(cacheKey);
    if (cacheIt != end(cache))
        return cacheIt->second;

    long long ways = 0;
    for (int i = 0;; i += static_cast<int>(*coinIt)) {
        auto remainder = n - i;
        if (remainder > 0)
            ways += getWaysImpl(remainder, coinIt + 1, coinItEnd, cache);
        else if (remainder < 0)
            break;
        else
            ways += 1;
    }

    cache[cacheKey] = ways;
    return ways;
}

long long getWays(long long n, const CoinsT& coins) {
    CacheT cache;
    return getWaysImpl(n, cbegin(coins), cend(coins), cache);
}


}
