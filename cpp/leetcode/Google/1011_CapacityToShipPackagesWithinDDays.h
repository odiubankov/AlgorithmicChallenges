//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
#ifndef ALGORITHMICCHALLENGES_1011_CAPACITYTOSHIPPACKAGESWITHINDDAYS_H
#define ALGORITHMICCHALLENGES_1011_CAPACITYTOSHIPPACKAGESWITHINDDAYS_H

#include <vector>
#include <numeric>

using namespace std;

bool checkCapacity(const vector<int>& weights, int D, int capacity) {
    int d = 1;
    int weight = 0;
    for (auto& w : weights) {
        weight += w;
        if (weight > capacity) {
            if (++d > D)
                return false;
            weight = w;
        }
    }
    return true;
}

int shipWithinDays(const vector<int>& weights, int D) {
    int minCapacity = *max_element(begin(weights), end(weights));
    int maxCapacity = accumulate(begin(weights), end(weights), 0);
    while (minCapacity < maxCapacity) {
        int mid = (minCapacity + maxCapacity) / 2;
        if (checkCapacity(weights, D, mid))
            maxCapacity = mid;
        else
            minCapacity = mid + 1;
    }
    return maxCapacity;
}

#endif //ALGORITHMICCHALLENGES_1011_CAPACITYTOSHIPPACKAGESWITHINDDAYS_H
