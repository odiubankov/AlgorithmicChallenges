//https://leetcode.com/problems/fruit-into-baskets/
#ifndef ALGORITHMICCHALLENGES_904_FRUITINTOBASKETS_H
#define ALGORITHMICCHALLENGES_904_FRUITINTOBASKETS_H

#include <vector>
#include <unordered_map>
using namespace std;

int totalFruit(const vector<int>& tree) {
    const size_t BinsCount = 2;
    if (tree.size() <= BinsCount)
        return tree.size();
    auto leftIt = begin(tree);
    const auto itE = end(tree);
    auto rightIt = leftIt + 1;
    unordered_map<int, size_t> fruitsCnt;
    ++fruitsCnt[*leftIt];
    for (;rightIt != itE; ++rightIt) {
        if (fruitsCnt.size() < BinsCount || fruitsCnt.find(*rightIt) != end(fruitsCnt))
            ++fruitsCnt[*rightIt];
        else
            break;
    }
    int maxFruits = distance(leftIt, rightIt);
    while (rightIt != itE) {
        for (;fruitsCnt.size() == BinsCount; ++leftIt) {
            if (--fruitsCnt[*leftIt] == 0)
                fruitsCnt.erase(*leftIt);
        }
        ++fruitsCnt[*rightIt];
        ++rightIt;
        for (;rightIt != itE; ++rightIt) {
            if (fruitsCnt.find(*rightIt) != end(fruitsCnt))
                ++fruitsCnt[*rightIt];
            else
                break;
        }
        int fruits = distance(leftIt, rightIt);
        maxFruits = max(maxFruits, fruits);
    }
    return maxFruits;
}

#endif //ALGORITHMICCHALLENGES_904_FRUITINTOBASKETS_H
