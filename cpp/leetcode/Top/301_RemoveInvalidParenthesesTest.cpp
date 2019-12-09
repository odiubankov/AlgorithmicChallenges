#include "301_RemoveInvalidParentheses.h"
#include <gtest/gtest.h>

TEST(RemoveInvalidParentheses, test) {
    ASSERT_EQ(2, removeInvalidParentheses("()())()").size());
}

TEST(RemoveInvalidParentheses, test2) {
    ASSERT_EQ(vector<string>{"()()"}, removeInvalidParentheses("()(()(("));
}

TEST(RemoveInvalidParentheses, test3) {
    ASSERT_EQ(2, removeInvalidParentheses("(((k()((").size());
}

TEST(RemoveInvalidParentheses, test4) {
    ASSERT_EQ(1, removeInvalidParentheses("())(((()m)(").size());
}
