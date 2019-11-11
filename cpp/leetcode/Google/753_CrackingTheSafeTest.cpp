#include "753_CrackingTheSafe.h"
#include <gtest/gtest.h>

TEST(CrackingTheSafe, test) {
    ASSERT_EQ("01", crackSafe(1, 2));
    ASSERT_EQ("00110", crackSafe(2, 2));
}
