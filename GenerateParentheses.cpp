#include "GenerateParentheses.h"
#include <gtest/gtest.h>


TEST(GenerateParentheses, test)
{
    generateparentheses::Solution solution;
    auto result = solution.generateParenthesis(3);
    ASSERT_EQ(result.size(), 5);
    ASSERT_TRUE(std::find(begin(result), end(result), "((()))") != end(result));
    ASSERT_TRUE(std::find(begin(result), end(result), "(()())") != end(result));
    ASSERT_TRUE(std::find(begin(result), end(result), "(())()") != end(result));
    ASSERT_TRUE(std::find(begin(result), end(result), "()(())") != end(result));
    ASSERT_TRUE(std::find(begin(result), end(result), "()()()") != end(result));
}
