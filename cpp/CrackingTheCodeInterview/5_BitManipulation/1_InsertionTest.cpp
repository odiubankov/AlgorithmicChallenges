#include "1_Insertion.h"
#include <gtest/gtest.h>

TEST(BitsInsertion, test) {
    uint32_t N = 0b10000000000;
    uint32_t M = 0b10011;
    insertBits(N, M, 2, 6);
    ASSERT_EQ(N, 0b10001001100);
}
