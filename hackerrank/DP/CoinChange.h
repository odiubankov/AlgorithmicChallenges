#pragma once
#include <unordered_map>

namespace hackerrank {

  using CacheT = std::unordered_map<long, long>;
  using CoinsT = std::vector<long>;

  long getWaysImpl(CacheT& cache, long n, const CoinsT& coins) {
    auto cacheIt = cache.find(n);
    if (cacheIt != std::end(cache))
      return cacheIt->second;

    long result = 0;
    for (auto coin : coins) {
      if (coin < n)
        result += getWaysImpl(cache, n - coin, coins);
      else if (coin == n)
        ++result;
    }

    cache[n] = result;
    return result;
  }

  long getWays(long n, const CoinsT& coins) {
    CacheT cache;
    return getWaysImpl(cache, n, coins);
  }
}
