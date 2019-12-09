#include "307_RangeSumQueryMutable.h"
#include <gtest/gtest.h>

TEST(RangeSumQuery, test) {
    vector<int> nums{1, 3, 5};
    NumArray na{nums};
    ASSERT_EQ(9, na.sumRange(0, 2));
}
