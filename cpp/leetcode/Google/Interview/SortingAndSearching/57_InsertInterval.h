//https://leetcode.com/problems/insert-interval/
#ifndef ALGORITHMICCHALLENGES_57_INSERTINTERVAL_H
#define ALGORITHMICCHALLENGES_57_INSERTINTERVAL_H

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //find first overlapped interval
    auto overlapIntervalsBegin = lower_bound(begin(intervals), end(intervals), vector<int>{newInterval.front(), 0});
    auto overlapIntervalsEnd = overlapIntervalsBegin;
    //merge with previous interval if needed
    if (overlapIntervalsBegin != begin(intervals) &&
        (overlapIntervalsBegin - 1)->back() >= newInterval.front()) {
        --overlapIntervalsBegin;
    }
    if (overlapIntervalsBegin != end(intervals))
        newInterval.front() = min(newInterval.front(), overlapIntervalsBegin->front());

    overlapIntervalsEnd = upper_bound(overlapIntervalsBegin, end(intervals), vector<int>{newInterval.back(), 0});
    if (overlapIntervalsEnd != end(intervals) && overlapIntervalsEnd->front() == newInterval.back()) {
        newInterval.back() = overlapIntervalsEnd->back();
        ++overlapIntervalsEnd;
    } else if (overlapIntervalsEnd != begin(intervals)) {
        newInterval.back() = max(newInterval.back(), (overlapIntervalsEnd - 1)->back());
    }

    intervals.erase(overlapIntervalsBegin, overlapIntervalsEnd);
    intervals.insert(upper_bound(begin(intervals), end(intervals), newInterval), newInterval);
    return intervals;
}

#endif //ALGORITHMICCHALLENGES_57_INSERTINTERVAL_H
