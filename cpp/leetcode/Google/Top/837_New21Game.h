//https://leetcode.com/problems/new-21-game/
#ifndef ALGORITHMICCHALLENGES_837_NEW21GAME_H
#define ALGORITHMICCHALLENGES_837_NEW21GAME_H

#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// Probability cache - N to Probability
using CacheT = unordered_map<int, double>;

// N - the answer should show probability of getting <=N points
// W - each time Alice gets from 1 to W points
// K - maximum value after which Alice stops playing
double chancesGetMore(int N, int K, int W, CacheT& cache) {
//    Check if probability was calculated already
    auto cacheIt = cache.find(N);
    if (cacheIt != end(cache))
        return cacheIt->second;

    double res = 0;
    //check probability for one move (W > N)
    if (W > N)
        res = static_cast<double>(W - N) / W;
    // Alice will play again after she throws some value 1 - W,
    // but not if she throws smth bigger than K
    int iterateUntil = min(W, K - 1);
    for (int i = 1; i <= iterateUntil; ++i)
        res += chancesGetMore(N - i, K - i, W, cache) / W;
    cache[N] = res;
    return res;
}

// N - the answer should show probability of getting <=N points
// W - each time Alice gets from 1 to W points
// K - maximum value after which Alice stops playing
double new21Game(int N, int K, int W) {
    if (K == 0)
        return 1.0;

    CacheT cache;
    return 1.0 - chancesGetMore(N, K, W, cache);
}

// N - the answer should show probability of getting <=N points
// W - each time Alice gets from 1 to W points
// K - maximum value after which Alice stops playing
double new21GameDP(int N, int K, int W) {
    if (K == 0)
        return 1.0;

    // Probabilities of getting each value from 0 to N + 1
    vector<double> dp(N + 1, 0);
    // 0 is 100% probability because it is always possible to not throw
    dp[0] = 1.0;
    double sum = dp[0];
    for (int i = 1; i <= N; ++i) {
        // It is possible to get i th amount of points
        // by throwing dice once and to get there from any
        // previous amount of points
        // this means the probability equally even distributed
        // between previous probabilities
        dp[i] = sum / W;
        //if K points - Alice won't drop dice anymore
        if (i < K)
            sum += dp[i];
        //running sum. subtract not relevant value if needed
        if (i >= W)
            sum -= dp[i - W];
    }
    //get the answer by summing up required probabilities
    double res = 0.0;
    for (size_t i = K; i <= N; ++i)
        res += dp[i];
    return res;
}

#endif //ALGORITHMICCHALLENGES_837_NEW21GAME_H
