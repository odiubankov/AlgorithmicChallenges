#include "253_MeetingRoomsII.h"
#include <gtest/gtest.h>

TEST(MeetingRooms, test) {
    std::vector<std::vector<int>> intervals1{{0, 30},{5, 10},{15, 20}};
    ASSERT_EQ(2, minMeetingRooms(intervals1));
    std::vector<std::vector<int>> intervals2{{7,10},{2,4}};
    ASSERT_EQ(1, minMeetingRooms(intervals2));

    ASSERT_EQ(2, minMeetingRoomsSimple(intervals1));
    ASSERT_EQ(1, minMeetingRoomsSimple(intervals2));
}
