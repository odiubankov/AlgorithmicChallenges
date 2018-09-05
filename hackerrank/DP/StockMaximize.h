#pragma once

#include <vector>
#include <algorithm>

namespace hackerrank
{

long long stockmax(std::vector<long long> prices)
{
    auto maxElement = max_element(begin(prices), end(prices));
    long long profit = 0;
    int sharesCnt = 0;
    for (auto it = begin(prices); it != end(prices); ++it)
    {
        if (*it == *maxElement)
        {
            profit += sharesCnt * (*it);
            sharesCnt = 0;
            maxElement = max_element(it + 1, end(prices));
        }
        else
        {
            profit -= *it;
            ++sharesCnt;
        }
    }

    return profit;
}

}