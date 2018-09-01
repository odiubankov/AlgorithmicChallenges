#pragma once

#include <bits/stdc++.h>

vector<string> split_string(string);

int knapsackImpl(std::unordered_map<int, int>& knapsackCache, int k, const vector<int>& arr)
{
    auto cacheIt = knapsackCache.find(k);
    if (cacheIt != end(knapsackCache))
        return cacheIt->second;

    int result = k;
    for (auto val : arr)
    {
        if (val == k) {
            result = 0;
            break;
        }

        if (val < k)
        {
            auto resultIt = knapsackImpl(knapsackCache, k - val, arr);
            result = std::min(result, resultIt);
        }
    }

    knapsackCache[k] = result;
    return result;
}

// Complete the unboundedKnapsack function below.
int unboundedKnapsack(int k, const vector<int>& arr)
{
    std::unordered_map<int, int> knapsackCache;
    return k - knapsackImpl(knapsackCache, k, arr);
}
