//https://leetcode.com/problems/fruit-into-baskets/
#ifndef ALGORITHMICCHALLENGES_904_FRUITINTOBASKETS_H
#define ALGORITHMICCHALLENGES_904_FRUITINTOBASKETS_H

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace {
    const size_t BinsCount = 2;
}

using FruitsT = unordered_map<int, size_t>;
using TreeIt = vector<int>::const_iterator;

void collectFruitsUntilPossible(FruitsT& fruits, TreeIt& rightIt, const TreeIt& endIt) {
    for (;rightIt != endIt; ++rightIt) {
        if (fruits.size() < BinsCount || fruits.find(*rightIt) != end(fruits))
            ++fruits[*rightIt];
        else
            break;
    }
}

int totalFruit(const vector<int>& tree) {
    if (tree.size() <= BinsCount)
        return tree.size();
    auto leftIt = cbegin(tree);
    auto rightIt = leftIt + 1;
    unordered_map<int, size_t> fruits;
    ++fruits[*leftIt];
    collectFruitsUntilPossible(fruits, rightIt, cend(tree));
    int maxFruits = distance(leftIt, rightIt);
    while (rightIt != end(tree)) {
        for (;fruits.size() == BinsCount; ++leftIt) {
            if (--fruits[*leftIt] == 0)
                fruits.erase(*leftIt);
        }
        ++fruits[*rightIt];
        ++rightIt;
        collectFruitsUntilPossible(fruits, rightIt, cend(tree));
        int fruits = distance(leftIt, rightIt);
        maxFruits = max(maxFruits, fruits);
    }
    return maxFruits;
}

#endif //ALGORITHMICCHALLENGES_904_FRUITINTOBASKETS_H
