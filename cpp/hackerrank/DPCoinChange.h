/**
* DP: Coin Change
*
* Cracking the Coding Interview Challenges
* https://www.hackerrank.com/domains/tutorials/cracking-the-coding-interview
*
* Copyright 2017 Oleksii Diubankov
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef HACKERRANK_DPCOINCHANGE_H
#define HACKERRANK_DPCOINCHANGE_H

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <iterator>
#include <functional>

namespace hackerrank
{

using MoneyChangeT = std::unordered_map<int, std::unordered_map<int, long long>>;
using CoinsT = std::vector<int>;
long long make_change_impl(CoinsT::iterator coinsBegin,
                           const CoinsT::iterator &coinsEnd,
                           int money,
                           MoneyChangeT &moneyChange)
{
    auto coinsCnt = distance(coinsBegin, coinsEnd);
    if (coinsCnt == 0)
        return 0;

    auto firstNominal = *coinsBegin;
    auto moneyIt = moneyChange.find(money);
    if (moneyIt != end(moneyChange)) {
        auto changeIt = moneyIt->second.find(firstNominal);
        if (changeIt != end(moneyIt->second))
            return changeIt->second;
    }

    long long change = 0;
    for (auto coinsIt = coinsBegin; coinsIt != coinsEnd; ++coinsIt) {
        auto nominal = *coinsIt;
        for (int i = 1;; ++i) {
            auto rest = money - nominal * i;
            if (rest < 0)
                break;

            if (0 == rest) {
                ++change;
                break;
            }

            change += make_change_impl(coinsIt + 1, coinsEnd, rest, moneyChange);
        }
    }

    moneyChange[money][firstNominal] = change;
    return change;
}

long long make_change(std::vector<int> coins, int money)
{
    if (money == 0)
        return 0;

    MoneyChangeT moneyChange;
    return make_change_impl(begin(coins), end(coins), money, moneyChange);
}

}//namespace hackerrank

#endif //HACKERRANK_DPCOINCHANGE_H
