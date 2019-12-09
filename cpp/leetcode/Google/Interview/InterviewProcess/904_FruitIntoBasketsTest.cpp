#include "904_FruitIntoBaskets.h"
#include <gtest/gtest.h>

TEST(CollectFruits, test) {
    ASSERT_EQ(5, totalFruit({3,3,3,1,2,1,1,2,3,3,4}));
}
