#include "BasicCalculator.h"
#include <gtest/gtest.h>


TEST(BasicCalculator, test)
{
    basiccalc::Solution basicCalc;
    EXPECT_EQ(basicCalc.calculate("3+2*2"), 7);
}