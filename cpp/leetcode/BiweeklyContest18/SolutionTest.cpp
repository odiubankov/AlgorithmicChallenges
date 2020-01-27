#include "Solution.h"
#include <gtest/gtest.h>

TEST(BiweeklyContest18, test) {
    vector<int> arr{2,3,1,5,4};
    ASSERT_EQ(10, maxValueAfterReverse(arr));
}
