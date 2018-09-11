#include "../SubStringSearchKMP.h"
#include <gtest/gtest.h>

namespace leetcode
{

TEST(SubStringSearchKMP, getLongestSuffixPrefixes)
{
    auto result = getLongestSuffixPrefixes("abcdeabc");
    std::vector<int> lsp = {0, 0, 0, 0, 0, 1, 2, 3};
    ASSERT_EQ(result, lsp);
}

TEST(SubStringSearchKMP, findSubstring)
{
    auto result = findSubstring("12345678", "56");
    ASSERT_EQ(result, 4);

    result = findSubstring("123234", "234");
    ASSERT_EQ(result, 3);

    result = findSubstring("xabananananasan", "ananas");
    ASSERT_EQ(result, 7);

    result = findSubstring("babba", "bbb");
    ASSERT_EQ(result, -1);

    result = findSubstring("aabaaabaaac", "aabaaac");
    ASSERT_EQ(result, 4);
}

}//namespace leetcode


