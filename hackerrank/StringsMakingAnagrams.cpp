#include "StringsMakingAnagrams.h"
#include <gtest/gtest.h>

TEST(StringsMakingAnagrams, test1)
{
    auto result = makinganagrams::number_needed("cde", "abc");
    ASSERT_EQ(result, 4);
}


TEST(StringsMakingAnagrams, test2)
{
    auto result = makinganagrams::number_needed("bacdc", "dcbacx");
    ASSERT_EQ(result, 1);
}


TEST(StringsMakingAnagrams, test3)
{
    auto result = makinganagrams::number_needed("a", "a");
    ASSERT_EQ(result, 0);
}


TEST(StringsMakingAnagrams, test4)
{
    auto result = makinganagrams::number_needed("aa", "aa");
    ASSERT_EQ(result, 0);
}


TEST(StringsMakingAnagrams, test5)
{
    auto result = makinganagrams::number_needed("ab", "ba");
    ASSERT_EQ(result, 0);
}


TEST(StringsMakingAnagrams, test6)
{
    auto result = makinganagrams::number_needed("abc", "cab");
    ASSERT_EQ(result, 0);
}


TEST(StringsMakingAnagrams, test7)
{
    auto result = makinganagrams::number_needed("abc", "bca");
    ASSERT_EQ(result, 0);
}

