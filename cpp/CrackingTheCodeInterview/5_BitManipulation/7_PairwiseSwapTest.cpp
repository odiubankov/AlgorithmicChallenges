#include "7_PairwiseSwap.h"
#include <gtest/gtest.h>

TEST(PairwiseSwap, test) {
    ASSERT_EQ(0b10101010, pairwiseSwap(0b01010101));
}
