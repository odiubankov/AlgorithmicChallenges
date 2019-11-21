//https://leetcode.com/problems/random-pick-with-weight/
#ifndef ALGORITHMICCHALLENGES_528_RANDOMPICKWITHWEIGHT_H
#define ALGORITHMICCHALLENGES_528_RANDOMPICKWITHWEIGHT_H

#include <vector>
#include <random>

using namespace std;

class Solution {
    vector<int> ranges;
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;

public:
    Solution(vector<int>& w) {
        int current = 0;
        for (auto val : w) {
            current += val;
            ranges.push_back(current);
        }
        uni = uniform_int_distribution<int>{0, ranges.back() - 1};
    }

    int pickIndex() {
        int targ = uni(rng);
        auto it = upper_bound(begin(ranges), end(ranges), targ);
        return distance(begin(ranges), it);
    }
};


#endif //ALGORITHMICCHALLENGES_528_RANDOMPICKWITHWEIGHT_H
