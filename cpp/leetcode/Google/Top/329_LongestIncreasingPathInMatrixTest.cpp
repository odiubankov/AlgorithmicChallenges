#include "329_LongestIncreasingPathInMatrix.h"
#include <gtest/gtest.h>

TEST(LongestIncreasingPath, test) {
    ASSERT_EQ(4, longestIncreasingPath({
                                           {9,9,4},
                                           {6,6,8},
                                           {2,1,1}
    }));
}

TEST(LongestIncreasingPath, test2) {
    ASSERT_EQ(4, longestIncreasingPath({
                                           {3,4,5},
                                           {3,2,6},
                                           {2,2,1}
                                       }));
}
