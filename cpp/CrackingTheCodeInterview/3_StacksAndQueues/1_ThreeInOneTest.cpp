#include "1_ThreeInOne.h"
#include <gtest/gtest.h>

TEST(ThreeInOne, Push10ToAll) {
    ThreeInOneStack threeInOne;
    for (int i = 0; i < 30; ++i) {
        if (i < 10) {
            threeInOne.push1(i);
        } else if (i >= 20) {
            threeInOne.push3(i);
        } else {
            threeInOne.push2(i);
        }
    }

    for (int i = 29; i >=0; --i) {
        int val = 0;
        if (i < 10) {
            val = threeInOne.pop1();
        } else if (i >= 20) {
            val = threeInOne.pop3();
        } else {
            val = threeInOne.pop2();
        }

        ASSERT_EQ(val, i);
    }
}
