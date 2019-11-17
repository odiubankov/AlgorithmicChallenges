//https://leetcode.com/problems/new-21-game/
#ifndef ALGORITHMICCHALLENGES_837_NEW21GAME_H
#define ALGORITHMICCHALLENGES_837_NEW21GAME_H

#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

using CacheT = unordered_map<int, double>;

double chancesGetMore(int N, int K, int W, CacheT& cache) {
    auto cacheIt = cache.find(N);
    if (cacheIt != end(cache))
        return cacheIt->second;
    double res = 0;
    if (W > N && K > 0)
        res = static_cast<double>(W - N) / W;
    int iterateUntil = min(W, K - 1);
    for (int i = 1; i <= iterateUntil; ++i)
        res += chancesGetMore(N - i, K - i, W, cache) / W;
    cache[N] = res;
    return res;
}

double new21Game(int N, int K, int W) {
    CacheT cache;
    return 1.0 - chancesGetMore(N, K, W, cache);
}

double new21GameDP(int N, int K, int W) {
    if (K == 0)
        return 1.0;

    vector<double> dp(N + 1, 0);
    dp[0] = 1.0;
    double sum = dp[0];
    for (int i = 1; i <= N; ++i) {
        dp[i] = sum / W;
        if (i < K)
            sum += dp[i];
        if (i >= W)
            sum -= dp[i - W];
    }
    double res = 0.0;
    for (size_t i = K; i <= N; ++i)
        res += dp[i];
    return res;
}

#endif //ALGORITHMICCHALLENGES_837_NEW21GAME_H
