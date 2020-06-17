#include "731_MyCalendarII.h"
#include <gtest/gtest.h>

TEST(MyCalendar, test) {
    MyCalendarTwo calendar;
    ASSERT_TRUE(calendar.book(10, 20));
    ASSERT_TRUE(calendar.book(50, 60));
    ASSERT_TRUE(calendar.book(10, 40));
    ASSERT_FALSE(calendar.book(5, 15));
    ASSERT_TRUE(calendar.book(5, 10));
    ASSERT_TRUE(calendar.book(25, 55));
}
