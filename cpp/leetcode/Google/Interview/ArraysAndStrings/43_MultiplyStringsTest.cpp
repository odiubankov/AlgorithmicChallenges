#include "43_MultiplyStrings.h"
#include <gtest/gtest.h>

TEST(MultiplyStrings, test) {
    ASSERT_EQ("56088", multiply("123", "456"));
    ASSERT_EQ("56088", multiplySimple("123", "456"));
}

TEST(MultiplyStrings, test2) {
    ASSERT_EQ("67308", multiply("237", "284"));
}
