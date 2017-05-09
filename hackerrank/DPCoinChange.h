#ifndef LEETCODESOLUTIONS_DPCOINCHANGE_H
#define LEETCODESOLUTIONS_DPCOINCHANGE_H

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

namespace hackerrank
{
    using CoinsT = std::unordered_set<int>;
    using ChangeCoinsT = set<vector<int>>;
    using ChangeT = std::unordered_map<int, ChangeCoinsT>;
    const ChangeCoinsT& makeChangeImpl(const CoinsT& coins, ChangeT& change, int money)
    {
        auto changeIt = change.find(money);
        if (changeIt != end(change))
            return changeIt->second;

        ChangeCoinsT changeCoins;
        for (int i = 1; i <= money/2; ++i)
        {
            auto firstIntervalChangeCoins = makeChangeImpl(coins, change, i);
            auto secondIntervalChangeCoins = makeChangeImpl(coins, change, money - i);
            for (const auto& firstItervalChange : firstIntervalChangeCoins)
            {
                for (const auto& secondIntervalChange : secondIntervalChangeCoins)
                {
                    vector<int> changeVal;
                    changeVal.reserve(firstItervalChange.size() + secondIntervalChange.size());
                    merge(begin(firstItervalChange), end(firstItervalChange), begin(secondIntervalChange), end(secondIntervalChange), back_inserter(changeVal));
                    changeCoins.insert(move(changeVal));
                }
            }
        }

        if (coins.find(money) != end(coins))
        {
            changeCoins.insert(vector<int>{money});
        }

        return change.emplace(money, changeCoins).first->second;
    }


    long long make_change(vector<int> coins, int money)
    {
        if (coins.empty())
            return  0;

        if (money == 0)
            return 0;

        CoinsT coinsSet { begin(coins), end(coins) };
        ChangeT change;
        return makeChangeImpl(coinsSet, change, money).size();
    }
}

#endif //LEETCODESOLUTIONS_DPCOINCHANGE_H
