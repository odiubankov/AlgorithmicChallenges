#include "621_TaskScheduler.h"
#include <gtest/gtest.h>

TEST(TasksScheduler, test) {
    ASSERT_EQ(10, leastInterval({'A','B','C','D','E','A','B','C','D','E'}, 4));
    ASSERT_EQ(10, leastIntervalCountEmptySlots({'A','B','C','D','E','A','B','C','D','E'}, 4));
}

TEST(TaskScheduler, test2) {
    ASSERT_EQ(16, leastInterval({'A','A','A','A','A','A','B','C','D','E','F','G'}, 2));
    ASSERT_EQ(16, leastIntervalCountEmptySlots({'A','A','A','A','A','A','B','C','D','E','F','G'}, 2));
}