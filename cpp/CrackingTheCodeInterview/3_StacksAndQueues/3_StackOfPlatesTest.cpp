#include "3_StackOfPlates.h"
#include <gtest/gtest.h>

TEST(StackOfPlates, test1) {
    DinnerPlates s{2};
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    ASSERT_EQ(s.popAtStack(0), 2);
    s.push(20);
    s.push(21);
    ASSERT_EQ(s.popAtStack(0), 20);
    ASSERT_EQ(s.popAtStack(2), 21);
    ASSERT_EQ(s.pop(), 5);
    ASSERT_EQ(s.pop(), 4);
    ASSERT_EQ(s.pop(), 3);
    ASSERT_EQ(s.pop(), 1);
    ASSERT_EQ(s.pop(), -1);
}

TEST(StackOfPlates, test2) {
    DinnerPlates s{1};
    s.push(1);
    s.push(2);
    s.push(3);
    ASSERT_EQ(s.popAtStack(1), 2);
    ASSERT_EQ(s.pop(), 3);
    ASSERT_EQ(s.pop(), 1);
}
