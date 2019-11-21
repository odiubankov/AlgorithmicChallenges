#include "844_BackspaceStringCompare.h"
#include <gtest/gtest.h>

TEST(BackspaceStringCompare, test) {
    ASSERT_TRUE(backspaceCompare("ab#c", "ad#c"));
}

TEST(BackspaceStringCompare, test2) {
    ASSERT_TRUE(backspaceCompare("a##c", "#a#c"));
}
