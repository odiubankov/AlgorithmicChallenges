//https://leetcode.com/problems/next-greater-element-iii/description/

#ifndef ALGORITHMICCHALLENGES_556_NEXTGREATERELEMENTIII_H
#define ALGORITHMICCHALLENGES_556_NEXTGREATERELEMENTIII_H

#include <string>
#include <iterator>
#include <algorithm>
#include <exception>
#include <set>

int nextGreaterElement(int n) {
    auto str = std::to_string(n);
    if (str.length() < 2) {
        return -1;
    }

    try {
        auto prevIt = str.rbegin();
        std::multiset<int> prevValues;
        for (auto it = prevIt + 1; it != str.rend(); ++it, ++prevIt) {
            if (*it < *prevIt) {
                prevValues.insert(*prevIt);
                int currentVal = *it;
                auto nextItemIt = prevValues.upper_bound(*it);
                *it = *nextItemIt;
                prevValues.erase(nextItemIt);
                prevValues.insert(currentVal);
                std::copy(prevValues.begin(), prevValues.end(), it.base());
                return std::stoi(str);
            }

            prevValues.insert(*prevIt);
        }
    } catch (const std::out_of_range&) {}

    return -1;
}

#endif //ALGORITHMICCHALLENGES_556_NEXTGREATERELEMENTIII_H
