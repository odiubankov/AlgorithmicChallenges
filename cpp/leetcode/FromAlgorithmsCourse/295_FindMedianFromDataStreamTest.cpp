#include "295_FindMedianFromDataStream.h"
#include <gtest/gtest.h>

TEST(FindMedian, test) {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    mf.addNum(3);
    ASSERT_DOUBLE_EQ(2.0, mf.findMedian());
}