#include "1716_CalculateMoneyInLeetcodeBank.h"
#include <gtest/gtest.h>

TEST(CalculateMoney, test) {
    ASSERT_EQ(totalMoney(4), 10);
    ASSERT_EQ(totalMoney(10), 37);
    ASSERT_EQ(totalMoney(20), 96);
}
