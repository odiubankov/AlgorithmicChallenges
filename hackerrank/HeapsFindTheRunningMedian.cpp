#include "HeapsFindTheRunningMedian.h"
#include <gtest/gtest.h>

TEST(HeapsFindTheRunningMedian, test1)
{
    auto result = hackerrank::heapsRunningMedian(vector<int>{1,2,3,4,5,6,7,8,9,10});
    auto expectedResult = vector<float>{1.0f, 1.5f, 2.0f, 2.5f, 3.0f, 3.5f, 4.0f, 4.5f, 5.0f, 5.5f};
    ASSERT_EQ(result, expectedResult);
}
