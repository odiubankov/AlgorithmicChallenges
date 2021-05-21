//https://leetcode.com/contest/biweekly-contest-11/problems/meeting-scheduler/
#ifndef ALGORITHMICCHALLENGES_1229_MEETINGSCHEDULER_H
#define ALGORITHMICCHALLENGES_1229_MEETINGSCHEDULER_H

#include <vector>
using namespace std;

vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
    sort(begin(slots1), end(slots1));
    sort(begin(slots2), end(slots2));
    auto it1 = begin(slots1);
    auto it2 = begin(slots2);
    for (;it1 != end(slots1) && it2 != end(slots2);) {
        int commonBegin = std::max(it1->front(), it2->front());
        int commonEnd = std::min(it1->back(), it2->back());
        if ((commonEnd - commonBegin) >= duration)
            return {commonBegin, commonBegin + duration};
        if (it1->back() < it2->back())
            ++it1;
        else
            ++it2;
    }
    return {};
}

#endif //ALGORITHMICCHALLENGES_1229_MEETINGSCHEDULER_H
