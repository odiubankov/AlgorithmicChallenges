#include "SubStringSearchKMP.h"
#include <gtest/gtest.h>

TEST(SubStringSearchKMP, getLongestSuffixPrefixes)
{
  auto result = kmp::getLongestSuffixPrefixes("abcdeabc");
  std::vector<int> lsp = { 0,0,0,0,0,1,2,3 };
  ASSERT_EQ(result, lsp);
}


TEST(SubStringSearchKMP, findSubstring)
{
  auto result = kmp::findSubstring("12345678", "56");
  ASSERT_EQ(result, 4);

  result = kmp::findSubstring("123234", "234");
  ASSERT_EQ(result, 3);

  result = kmp::findSubstring("xabananananasan", "ananas");
  ASSERT_EQ(result, 7);

  result = kmp::findSubstring("babba", "bbb");
  ASSERT_EQ(result, -1);

  result = kmp::findSubstring("aabaaabaaac", "aabaaac");
  ASSERT_EQ(result, 4);
}

