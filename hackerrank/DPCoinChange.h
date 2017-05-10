#ifndef LEETCODESOLUTIONS_DPCOINCHANGE_H
#define LEETCODESOLUTIONS_DPCOINCHANGE_H

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <iterator>
#include <functional>

using namespace std;

namespace hackerrank
{
    using MoneyChangeT = std::unordered_map<int, std::unordered_map<int, long long>>;
    using CoinsT = vector<int>;
    long long make_change_impl(CoinsT::iterator coinsBegin, const CoinsT::iterator& coinsEnd, int money, MoneyChangeT& moneyChange)
    {
      auto coinsCnt = distance(coinsBegin, coinsEnd);
      if (coinsCnt == 0)
        return 0;

      auto firstNominal = *coinsBegin;
      auto moneyIt = moneyChange.find(money);
      if (moneyIt != end(moneyChange))
      {
        auto changeIt = moneyIt->second.find(firstNominal);
        if (changeIt != end(moneyIt->second))
          return changeIt->second;
      }

      long long change = 0;
      for (auto coinsIt = coinsBegin; coinsIt != coinsEnd; ++coinsIt)
      {
        auto nominal = *coinsIt;
        for (int i = 1;; ++i)
        {
          auto rest = money - nominal * i;
          if (rest < 0)
            break;

          if (0 == rest)
          {
            ++change;
            break;
          }

          change += make_change_impl(coinsIt + 1, coinsEnd, rest, moneyChange);
        }
      }

      moneyChange[money][firstNominal] = change;
      return change;
    }


    long long make_change(vector<int> coins, int money)
    {
      if (money == 0)
        return 0;

      MoneyChangeT moneyChange;
      return make_change_impl(begin(coins), end(coins), money, moneyChange);
    }
}

#endif //LEETCODESOLUTIONS_DPCOINCHANGE_H
