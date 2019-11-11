//https://leetcode.com/problems/meeting-rooms-ii/
#ifndef ALGORITHMICCHALLENGES_253_MEETINGROOMSII_H
#define ALGORITHMICCHALLENGES_253_MEETINGROOMSII_H

#include <vector>
#include <algorithm>

int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty())
        return 0;
    std::sort(begin(intervals), end(intervals),
        [](const auto& a, const auto& b) { return a.front() < b.front(); });
    std::vector<int> rooms(intervals.size(), 1);
    for (std::size_t i = 0; i < intervals.size(); ++i) {
        for (auto j = i + 1; j < intervals.size() && intervals[j].front() < intervals[i].back(); ++j) {
            ++rooms[j];
        }
    }
    return *std::max_element(begin(rooms), end(rooms));
}

int minMeetingRoomsSimple(std::vector<std::vector<int>>& intervals) {
    std::vector<int> begins, ends;
    begins.reserve(intervals.size());
    ends.reserve(intervals.size());
    for (const auto& interval : intervals) {
        begins.push_back(interval.front());
        ends.push_back(interval.back());
    }
    sort(begin(begins), end(begins));
    sort(begin(ends), end(ends));
    std::size_t beginIndex = 0, endIndex = 0;
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

#endif //ALGORITHMICCHALLENGES_253_MEETINGROOMSII_H
