//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#ifndef ALGORITHMICCHALLENGES_121_BESTTIMETOBUYANDSELLSTOCK_H
#define ALGORITHMICCHALLENGES_121_BESTTIMETOBUYANDSELLSTOCK_H

#include <vector>
#include <limits>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int minPrice = numeric_limits<int>::max();
    int maxProfit_ = 0;
    for (auto price : prices) {
        int profit = price - minPrice;
        maxProfit_ = max(maxProfit_, profit);
        minPrice = min(minPrice, price);
    }
    return maxProfit_;
}

#endif //ALGORITHMICCHALLENGES_121_BESTTIMETOBUYANDSELLSTOCK_H
