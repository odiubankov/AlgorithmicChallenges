#include "IntersectionOfThreeSortedArrays.h"
#include <gtest/gtest.h>

TEST(SolutionItersectionOfThreeSortedArrays, test) {
    SolutionItersectionOfThreeSortedArrays s;
    std::vector<int> exRes{1,5};
    ASSERT_EQ(s.arraysIntersection({1,2,3,4,5}, {1,2,5,7,9}, {1,3,4,5,8}), exRes);
}
