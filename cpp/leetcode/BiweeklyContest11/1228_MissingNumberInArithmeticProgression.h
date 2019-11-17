//https://leetcode.com/contest/biweekly-contest-11/problems/missing-number-in-arithmetic-progression/
#ifndef ALGORITHMICCHALLENGES_1228_MISSINGNUMBERINARITHMETICPROGRESSION_H
#define ALGORITHMICCHALLENGES_1228_MISSINGNUMBERINARITHMETICPROGRESSION_H

#include <vector>
#include <limits>
#include <array>

using namespace std;

int missingNumber(const vector<int>& arr) {
    auto diff = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); ++i) {
        auto nextDiff = arr[i] - arr[i - 1];
        if (abs(nextDiff) < abs(diff)) {
            diff = nextDiff;
            break;
        }
    }

    for (std::size_t i = 1; i < arr.size(); ++i) {
        if ((arr[i] - arr[i - 1]) != diff)
            return arr[i - 1] + diff;
    }
    return 0;
}

#endif //ALGORITHMICCHALLENGES_1228_MISSINGNUMBERINARITHMETICPROGRESSION_H
