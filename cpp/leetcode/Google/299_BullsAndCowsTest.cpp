#include "299_BullsAndCows.h"
#include <gtest/gtest.h>

TEST(BullsAndCows, test) {
    ASSERT_EQ("1A3B", getHint("1807", "7810"));
}