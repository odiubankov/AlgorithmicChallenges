//https://leetcode.com/problems/meeting-rooms-ii/
#ifndef ALGORITHMICCHALLENGES_253_MEETINGROOMSII_H
#define ALGORITHMICCHALLENGES_253_MEETINGROOMSII_H

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty())
        return 0;
    sort(begin(intervals), end(intervals),
        [](const auto& a, const auto& b) { return a.front() < b.front(); });
    vector<int> rooms(intervals.size(), 1);
    for (size_t i = 0; i < intervals.size(); ++i) {
        for (auto j = i + 1; j < intervals.size() && intervals[j].front() < intervals[i].back(); ++j) {
            ++rooms[j];
        }
    }
    return *max_element(begin(rooms), end(rooms));
}

int minMeetingRoomsSimple(std::vector<std::vector<int>>& intervals) {
    vector<int> begins, ends;
    begins.reserve(intervals.size());
    ends.reserve(intervals.size());
    for (const auto& interval : intervals) {
        begins.push_back(interval.front());
        ends.push_back(interval.back());
    }
    sort(begin(begins), end(begins));
    sort(begin(ends), end(ends));
    size_t beginIndex = 0, endIndex = 0;
    int rooms = 0, minRooms = 0;
    while (beginIndex < begins.size()) {
        if (begins[beginIndex] < ends[endIndex]) {
            ++rooms;
            if (rooms > minRooms)
                minRooms = rooms;
            ++beginIndex;
        } else {
            --rooms;
            ++endIndex;
        }
    }
    return minRooms;
}

int minMeetingRoomsPriorityQueue(vector<std::vector<int>>& intervals) {
    sort(begin(intervals), end(intervals),
        [](const auto& interval1, const auto& interval2) {
            return interval1.front() < interval2.front();
    });
    priority_queue<int, vector<int>, greater<>> intervalEnds;
    int rooms = 0, minRooms = 0;
    for (auto intervalIt = begin(intervals); intervalIt != end(intervals);) {
        if (intervalEnds.empty() || intervalIt->front() < intervalEnds.top()) {
            ++rooms;
            minRooms = max(minRooms, rooms);
            intervalEnds.push(intervalIt->back());
            ++intervalIt;
        } else {
            --rooms;
            intervalEnds.pop();
        }
    }
    return minRooms;
}

#endif //ALGORITHMICCHALLENGES_253_MEETINGROOMSII_H
