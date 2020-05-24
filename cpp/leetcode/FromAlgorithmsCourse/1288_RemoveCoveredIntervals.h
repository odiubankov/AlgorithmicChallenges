//https://leetcode.com/problems/remove-covered-intervals/
#ifndef ALGORITHMICCHALLENGES_1288_REMOVECOVEREDINTERVALS_H
#define ALGORITHMICCHALLENGES_1288_REMOVECOVEREDINTERVALS_H

#include <vector>
#include <queue>
#include <limits>

using namespace std;

using IntervalT = vector<int>;

struct IntervalComp {
    bool operator()(IntervalT const * int1, IntervalT const * int2) const noexcept {
        if (int1->front() == int2->front()) {
            return int1->back() < int2->back();
        }
        return int1->front() > int2->front();
    }
};

// Greedy Algorithm
//
// The idea of greedy algorithm is to pick the locally optimal move at each step,
// which would lead to the globally optimal solution.
int removeCoveredIntervals(vector<IntervalT> const& intervals) {
    priority_queue<IntervalT const*, vector<IntervalT const*>, IntervalComp> intervalsQueue;
    for (auto& interval : intervals) {
        intervalsQueue.push(&interval);
    }
    int lastEnd = numeric_limits<int>::lowest();
    int intervalsCnt = 0;
    while (!intervalsQueue.empty()) {
        auto nextInterval = intervalsQueue.top();
        if (nextInterval->back() > lastEnd) {
            ++intervalsCnt;
            lastEnd = nextInterval->back();
        }
        intervalsQueue.pop();
    }
    return intervalsCnt;
}

#endif //ALGORITHMICCHALLENGES_1288_REMOVECOVEREDINTERVALS_H
