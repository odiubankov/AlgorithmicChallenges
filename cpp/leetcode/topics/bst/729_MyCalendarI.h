// https://leetcode.com/problems/my-calendar-i/
#ifndef ALGORITHMICCHALLENGES_729_MYCALENDARI_H
#define ALGORITHMICCHALLENGES_729_MYCALENDARI_H

#include <map>

// scenarios:
// start in the other interval
// end in the other interval
// both are in the other interval - covered by previous two

class MyCalendar {
public:
    std::map<int, int> bookings;
    bool book(int start, int end) {
        auto bookingIt = bookings.lower_bound(start);
        if (bookingIt != bookings.end()) {
            // start of another interval is within new interval
            if (bookingIt->first < end)
                return false;
        }

        if (bookingIt != bookings.begin()) {
            auto prevIt = bookingIt;
            --prevIt;
            // end of another interval is within new interval
            if (prevIt->second > start)
                return false;
        }

        bookings[start] = end;
        return true;
    }
};

#endif //ALGORITHMICCHALLENGES_729_MYCALENDARI_H
