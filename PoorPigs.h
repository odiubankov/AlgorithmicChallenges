// https://leetcode.com/problems/poor-pigs/#/description

#ifndef LEETCODESOLUTIONS_POORPIGS_H
#define LEETCODESOLUTIONS_POORPIGS_H

#include <cmath>

using namespace std;

namespace poorpigs
{

class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        auto attemptsCnt = static_cast<unsigned>(minutesToTest / minutesToDie);
        for (auto i = 1u;; ++i) {
            if (buckets <= pow(attemptsCnt + 1, i))
                return i;
        }
    }
};
};

#endif //LEETCODESOLUTIONS_POORPIGS_H
