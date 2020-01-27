#include "215_KthLargestElementInAnArray.h"
#include <gtest/gtest.h>

TEST(KthLargestElementInAnArray, test) {
    vector<int> vals{3,2,1,5,6,4};
    ASSERT_EQ(5,findKthLargestQuickSelect(vals, 2));
}
