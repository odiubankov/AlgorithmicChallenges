#include "4_MedianOfTwoSortedArrays.h"
#include <gtest/gtest.h>

TEST(MedianOfTwoSortedArrays, test) {
    SolutionMedianOfTwoSortedArrays s;
    ASSERT_DOUBLE_EQ(2.0, s.findMedianSortedArraysNoAdditionalMemory({1, 3}, {2}));
    ASSERT_DOUBLE_EQ(2.5, s.findMedianSortedArraysNoAdditionalMemory({1, 2}, {3, 4}));
    ASSERT_DOUBLE_EQ(2.5, s.findMedianSortedArraysNoAdditionalMemory({}, {2, 3}));
    ASSERT_DOUBLE_EQ(2.0, s.findMedianSortedArraysNoAdditionalMemory({1}, {2, 3}));
    ASSERT_DOUBLE_EQ(3.0, s.findMedianSortedArraysNoAdditionalMemory({1}, {2, 3, 4, 5}));

    ASSERT_DOUBLE_EQ(2.0, s.findMedianSortedArraysMergeSort({1, 3}, {2}));
    ASSERT_DOUBLE_EQ(2.5, s.findMedianSortedArraysMergeSort({1, 2}, {3, 4}));
    ASSERT_DOUBLE_EQ(2.5, s.findMedianSortedArraysMergeSort({}, {2, 3}));
    ASSERT_DOUBLE_EQ(2.0, s.findMedianSortedArraysMergeSort({1}, {2, 3}));
    ASSERT_DOUBLE_EQ(3.0, s.findMedianSortedArraysMergeSort({1}, {2, 3, 4, 5}));
}
