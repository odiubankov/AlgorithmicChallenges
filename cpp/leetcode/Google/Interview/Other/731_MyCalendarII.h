//https://leetcode.com/problems/my-calendar-ii/
#ifndef ALGORITHMICCHALLENGES_731_MYCALENDARII_H
#define ALGORITHMICCHALLENGES_731_MYCALENDARII_H

#include <map>
#include <vector>
using namespace std;

using OverlapT = pair<int, int>;

class MyCalendarTwo {
    multimap<int, int> bookings;
public:
    bool book(int startBooking, int endBooking) {
        vector<OverlapT> overlaps;
        for (auto bookingIt = begin(bookings);
            bookingIt != end(bookings) && bookingIt->first < endBooking;
            ++bookingIt) {
            if (bookingIt->second > startBooking)
                overlaps.emplace_back(max(startBooking, bookingIt->first), min(endBooking, bookingIt->second));
        }
        if (!overlaps.empty()) {
            for (auto overlapIt = begin(overlaps) + 1; overlapIt != end(overlaps); ++overlapIt) {
                if (overlapIt->first < (overlapIt - 1)->second)
                    return false;
            }
        }
        bookings.emplace(startBooking, endBooking);
        return true;
    }
};

#endif //ALGORITHMICCHALLENGES_731_MYCALENDARII_H
