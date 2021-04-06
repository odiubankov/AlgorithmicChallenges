#include "301_RemoveInvalidParentheses.h"
#include <gtest/gtest.h>

TEST(RemoveInvalidParentheses, test) {
    ASSERT_EQ(2, removeInvalidParentheses_dfs("()())()").size());
}

TEST(RemoveInvalidParentheses, test2) {
    ASSERT_EQ(vector<string>{"()()"}, removeInvalidParentheses_dfs("()(()(("));
}

TEST(RemoveInvalidParentheses, test3) {
    ASSERT_EQ(2, removeInvalidParentheses_dfs("(((k()((").size());
}

TEST(RemoveInvalidParentheses, test4) {
    ASSERT_EQ(1, removeInvalidParentheses_dfs("())(((()m)(").size());
}

TEST(RemoveInvalidParentheses, test5) {
    ASSERT_EQ(1, removeInvalidParentheses_dfs(")(").size());
}
