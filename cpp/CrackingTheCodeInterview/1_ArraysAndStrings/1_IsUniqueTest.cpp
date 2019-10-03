#include "1_IsUnique.h"
#include <gtest/gtest.h>

TEST(IsUnique, unique) {
    ASSERT_TRUE(isUnique("1234567890"));
}

TEST(IsUnique, nonUnique) {
    ASSERT_FALSE(isUnique("12345678901"));
}
