#include "1717_MaximumScoreFromRemovingSubstrings.h"
#include <gtest/gtest.h>

TEST(maxGain, test) {
    ASSERT_EQ(maximumGain("cdbcbbaaabab", 4, 5), 19);
    ASSERT_EQ(maximumGain("aabbaaxybbaabb", 5, 4), 20);
}
