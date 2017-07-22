#include "StringOneAway.h"
#include <gtest/gtest.h>

TEST(StringOneAway, test1)
{
    auto res = strpermutation::isOneAway("pale", "ple");
    ASSERT_TRUE(res);

    res = strpermutation::isOneAway("pales", "pale");
    ASSERT_TRUE(res);

    res = strpermutation::isOneAway("pale", "bale");
    ASSERT_TRUE(res);

    res = strpermutation::isOneAway("pale", "bake");
    ASSERT_FALSE(res);
}

