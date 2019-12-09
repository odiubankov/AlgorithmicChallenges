#include "247_StrobogrammaticNumberII.h"
#include <gtest/gtest.h>

TEST(StroboNumber, test) {
    ASSERT_TRUE(!findStrobogrammatic(4).empty());
}
