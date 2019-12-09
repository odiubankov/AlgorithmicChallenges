//https://leetcode.com/problems/next-closest-time/
#ifndef ALGORITHMICCHALLENGES_681_NEXTCLOSESTTIME_H
#define ALGORITHMICCHALLENGES_681_NEXTCLOSESTTIME_H

#include <string>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

string formatTime(const vector<int>& time) {
    stringstream ss;
    for (size_t i = 0; i < time.size(); ++i) {
        ss << time[i];
        if (i == 1)
            ss << ":";
    }
    return ss.str();
}

string updateTimeAndFormat(vector<int>& time, size_t posToUpdate, int val, int followingVal = 0) {
    auto itToUpdate = begin(time) + posToUpdate;
    *itToUpdate = val;
    fill(itToUpdate + 1, end(time), followingVal);
    return formatTime(time);
}

string nextClosestTime(string time) {
    set<int> digits;
    vector<int> closestTime;
    closestTime.reserve(4);
    for (auto c : time) {
        if (c != ':') {
            int digit = c - '0';
            digits.insert(c - '0');
            closestTime.push_back(digit);
        }
    }

    assert(closestTime.size() == 4);//e.g. 12:00
    auto nextDigitIt = digits.upper_bound(closestTime[3]);
    if (nextDigitIt != end(digits)) {
        return updateTimeAndFormat(closestTime, 3, *nextDigitIt, *begin(digits));
    }

    nextDigitIt = digits.upper_bound(closestTime[2]);
    if (nextDigitIt != end(digits) && *nextDigitIt < 6) {
        return updateTimeAndFormat(closestTime, 2, *nextDigitIt, *begin(digits));
    }

    nextDigitIt = digits.upper_bound(closestTime[1]);
    if (nextDigitIt != end(digits) && (*nextDigitIt < 4 || closestTime[0] < 2)) {
        return updateTimeAndFormat(closestTime, 1, *nextDigitIt, *begin(digits));
    }

    nextDigitIt = digits.upper_bound(closestTime[0]);
    if (nextDigitIt != end(digits) && (*nextDigitIt < 2 || (*nextDigitIt == 2 && closestTime[1] < 4))) {
        return updateTimeAndFormat(closestTime, 0, *nextDigitIt, *begin(digits));
    }

    return updateTimeAndFormat(closestTime, 0, *begin(digits), *begin(digits));
}

#endif //ALGORITHMICCHALLENGES_681_NEXTCLOSESTTIME_H
