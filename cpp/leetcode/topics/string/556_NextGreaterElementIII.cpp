#include "556_NextGreaterElementIII.h"
#include <gtest/gtest.h>

TEST(NextGreaterElement, test) {
    ASSERT_EQ(nextGreaterElement(230241), 230412);
    ASSERT_EQ(nextGreaterElement(2147483476), 2147483647);
}
