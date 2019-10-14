//https://leetcode.com/contest/weekly-contest-158/problems/dice-roll-simulation/
#ifndef ALGORITHMICCHALLENGES_DICEROLLSIMULATION_H
#define ALGORITHMICCHALLENGES_DICEROLLSIMULATION_H

#include <unordered_map>
#include <vector>

class SolutionDiceRollSimulation {
public:
    const long MODULO = 1000000007;
    using CacheT = std::unordered_map<int, std::unordered_map<int, std::unordered_map<int, long> > >;
    long finishWithDiceCnt(int n, int cnt, int dice, const std::vector<int>& rollMax, CacheT& cache) {
        if (n == cnt) {
            return 1;
        }

        if (n < cnt) {
            return 0;
        }

        auto cacheIt = cache.find(n);
        if (cacheIt != end(cache)) {
            auto diceIt = cacheIt->second.find(dice);
            if (diceIt != end(cacheIt->second)) {
                auto cntIt = diceIt->second.find(cnt);
                if (cntIt != end(diceIt->second)) {
                    return cntIt->second;
                }
            }
        }

        long result = 0;
        if (cnt > 1) {
            result = finishWithDiceCnt(n - 1, cnt - 1, dice, rollMax, cache);
        } else {
            for (int i = 0; i < 6; ++i) {
                if (i == dice) {
                    continue;
                }

                for (int j = 1; j <= rollMax[i]; ++j) {
                    result += finishWithDiceCnt(n - 1, j, i, rollMax, cache);
                    result %= MODULO;
                }
            }
        }

        cache[n][dice][cnt] = result;
        return result;
    }

    int dieSimulator(int n, const std::vector<int>& rollMax) {
        CacheT cache;
        long result = 0;
        for (int i = 0; i < 6; ++i) {
            for (int j = 1; j <= rollMax[i]; ++j) {
                result += (finishWithDiceCnt(n, j, i, rollMax, cache) % MODULO);
                result %= MODULO;
            }
        }
        return static_cast<int>(result);
    }
};

#endif //ALGORITHMICCHALLENGES_DICEROLLSIMULATION_H
