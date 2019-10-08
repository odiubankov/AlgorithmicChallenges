#include "5_SortStack.h"
#include <gtest/gtest.h>

TEST(SortStack, test) {
    std::stack<int> s;
    for (int i = 0; i < 10; ++i)
        s.push(i);
    sort(s);
    for (int i = 0; i < 10; ++i) {
        ASSERT_EQ(i, s.top());
        s.pop();
    }
}
