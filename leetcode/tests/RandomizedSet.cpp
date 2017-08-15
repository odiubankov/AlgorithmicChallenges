#include "../RandomizedSet.h"
#include <gtest/gtest.h>

namespace leetcode
{

TEST(RandomizedSet, test)
{
    RandomizedSet set1;
    EXPECT_TRUE(set1.insert(1));
    EXPECT_TRUE(set1.insert(2));
    EXPECT_TRUE(set1.insert(3));
    EXPECT_TRUE(set1.remove(3));
    EXPECT_TRUE(set1.remove(2));
    EXPECT_TRUE(set1.remove(1));
    EXPECT_TRUE(set1.insert(1));
    EXPECT_TRUE(set1.insert(2));
    EXPECT_TRUE(set1.insert(3));
    EXPECT_FALSE(set1.insert(3));
    EXPECT_FALSE(set1.insert(2));
    EXPECT_FALSE(set1.insert(1));
    EXPECT_TRUE(set1.remove(2));
    EXPECT_FALSE(set1.remove(2));
    for (int i = 0; i < 10; ++i) {
        auto randomNumver = set1.getRandom();
        EXPECT_TRUE(randomNumver == 1 || randomNumver == 3);
    }
}

}//namespace leetcode

