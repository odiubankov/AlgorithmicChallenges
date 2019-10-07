#include "2_StackMin.h"
#include <gtest/gtest.h>

TEST(StackMin, ascending) {
    StackMin stackMin;
    for (int i = 0; i < 5; ++i)
        stackMin.push(i);

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(0, stackMin.min());
        stackMin.pop();
    }
}

TEST(StackMin, descending) {
    StackMin stackMin;
    for (int i = 4; i >= 0; --i)
        stackMin.push(i);

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(i, stackMin.min());
        stackMin.pop();
    }
}
