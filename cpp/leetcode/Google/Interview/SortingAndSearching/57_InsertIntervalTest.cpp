#include "57_InsertInterval.h"
#include <gtest/gtest.h>

TEST(InsertInterval, test) {
    vector<vector<int>> intervals{{1,3},{6,9}};
    vector<int> newInterval{2,5};
    vector<vector<int>> resIntervals{{1,5},{6,9}};
    ASSERT_EQ(resIntervals, insert(intervals, newInterval));
}

TEST(InsertInterval, test2) {
    vector<vector<int>> intervals{{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval{4,8};
    vector<vector<int>> resIntervals{{1,2},{3,10},{12,16}};
    ASSERT_EQ(resIntervals, insert(intervals, newInterval));
}

TEST(InsertInterval, test3) {
    vector<vector<int>> intervals{{1,5}};
    vector<int> newInterval{2,3};
    vector<vector<int>> resIntervals{{1,5}};
    ASSERT_EQ(resIntervals, insert(intervals, newInterval));
}